#include <iostream>
#include <cmath>
using namespace std;

// Функция, для которой ищем корень
double f(double x)
{
    return exp(x) - 2 * pow(x - 1, 2);
}

// Первая производная функции
double f_prime(double x)
{
    return exp(x) - 4 * (x - 1);
}

// Вторая производная функции
double f_Dprime(double x)
{
    return exp(x) - 4;
}

// Метод простых итераций (фиксированной точки)
double simple_iteration(double x0, double epsilon) {
    printf("МЕТОД ПРОСТЫХ ИТЕРАЦИЙ \n");
    double x1;
    int n = 1;
    do
    {
        x1 = x0 - 0.3 * f(x0); // Итерационная формула
        // Проверка условий сходимости
        if (fabs(x1 - x0) <= epsilon && fabs(f(x1)) <= epsilon) {
            printf("N: %d    Xn: %f    Xn+1: %f      |Xn+1 - Xn|: %f    |F(Xn+1)|: %f    \n", n, x0, x1, fabs(x1 - x0), fabs(f(x1)));
            break;
        }
        printf("N: %d    Xn: %f    Xn+1: %f    |Xn+1 - Xn|: %f    |F(Xn+1)|: %f    \n", n, x0, x1, fabs(x1 - x0), fabs(f(x1)));
        x0 = x1;
        n++;
        // Предохранение от бесконечного цикла
        if (n > 100)
        {
            cout << "Не выполнено достаточное условие сходимости для метода простых итераций" << endl;
            break;
        }
    } while (true);
    cout << "Кол-во итераций МПИ: " << n << endl;
    return x1;
}

// Классический метод Ньютона (касательная)
double newton_method(double x0, double epsilon)
{
    printf("МЕТОД НЬЮТОНА \n");
    double x1;
    int n = 1;
    do
    {
        x1 = x0 - f(x0) / f_prime(x0); // Формула Ньютона
        // Проверка условий сходимости
        if (fabs(x1 - x0) < epsilon && fabs(f(x1)) <= epsilon) {
            printf("N: %d    Xn: %f    Xn+1: %f    |Xn+1 - Xn|: %f    |F(Xn+1)|: %f    \n", n, x0, x1, fabs(x1 - x0), fabs(f(x1)));
            break;
        }
        // Достаточное условие сходимости: f(x0) * f''(x0) > 0
        if (f(x0) * f_Dprime(x0) <= 0) {
            cout << "Не выполняется достаточное условие сходимости для метода Ньютона!" << endl;
            return 1;
        }
        printf("N: %d    Xn: %f    Xn+1: %f    |Xn+1 - Xn|: %f    |F(Xn+1)|: %f    \n", n, x0, x1, fabs(x1 - x0), fabs(f(x1)));
        x0 = x1;
        n++;
    } while (true);
    cout << "Кол-во итераций МН: " << n << endl;
    return x1;
}

// Модифицированный метод Ньютона (с фиксированной производной)
double modified_newton(double x0, double epsilon)
{
    printf("МОДИФИЦИРОВАННЫЙ МЕТОД НЬЮТОНА \n");
    double f_prime_const = f_prime(x0); // Значение производной фиксируется в начале
    double x1;
    int n = 1;
    do
    {
        x1 = x0 - f(x0) / f_prime_const; // Используем фиксированное значение производной
        if (fabs(x1 - x0) < epsilon && fabs(f(x1)) <= epsilon) {
            printf("N: %d    Xn: %f    Xn+1: %f    |Xn+1 - Xn|: %f    |F(Xn+1)|: %f    \n", n, x0, x1, fabs(x1 - x0), fabs(f(x1)));
            break;
        }
        if (f(x0) * f_Dprime(x0) <= 0) {
            cout << "Не выполняется достаточное условие сходимости для модифицированного метода Ньютона!" << endl;
            return 1;
        }
        printf("N: %d    Xn: %f    Xn+1: %f    |Xn+1 - Xn|: %f    |F(Xn+1)|: %f    \n", n, x0, x1, fabs(x1 - x0), fabs(f(x1)));
        x0 = x1;
        n++;
    } while (true);
    cout << "Кол-во итераций ММН: " << n << endl;
    return x1;
}

int main()
{
    setlocale(LC_ALL, "rus"); // Русская локализация для корректного вывода текста
    double x0 = 0;
    cout << "Введите x0: " << endl;
    double x0Newton;
    cin >> x0Newton;
    x0 = x0Newton;

    // Первая точность
    double epsilon = 0.001;
    cout << "Точность: " << epsilon << endl << endl;

    // Запуск всех трёх методов
    cout << "Метод простых итераций: " << simple_iteration(x0, epsilon) << endl << endl;
    cout << "Метод Ньютона: " << newton_method(x0Newton, epsilon) << endl << endl;
    cout << "Модифицированный метод Ньютона: " << modified_newton(x0Newton, epsilon) << endl << endl;

    // Более строгая точность
    epsilon /= 100.00;
    cout << "Точность: " << epsilon << endl << endl;

    // Повторный запуск методов с новой точностью
    cout << "Метод простых итераций: " << simple_iteration(x0, epsilon) << endl << endl;
    cout << "Метод Ньютона: " << newton_method(x0Newton, epsilon) << endl << endl;
    cout << "Модифицированный метод Ньютона: " << modified_newton(x0Newton, epsilon) << endl << endl;

    return 0;
}
