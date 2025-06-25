#include <iostream>     // для ввода/вывода
#include <cmath>        // для математических функций (sqrt, atan и т.д.)
#include <iomanip>      // для управления форматированием вывода
using namespace std;

// Исходная функция: f(x) = 1 / (4 + x^2)
double f(double x) {
	return 1.0 / (4 + x * x);
}

// Метод трапеций для приближённого вычисления определённого интеграла
double trapezoidal(double a, double b, int n) {
	double h = (b - a) / n;             // шаг
	double sum = 0.5 * (f(a) + f(b));   // первая и последняя точки с коэффициентом 0.5
	for (int i = 1; i < n; ++i) {
		sum += f(a + i * h);           // сумма значений в остальных точках
	}
	return sum * h;                    // умножение суммы на шаг
}

// Метод Симпсона (n должно быть чётным)
double simpson(double a, double b, int n) {
	double h = (b - a) / n;
	double sum = f(a) + f(b);
	for (int i = 1; i < n; ++i) {
		if (i % 2 == 0) {
			sum += 2 * f(a + i * h);   // чётные индексы — коэффициент 2
		}
		else {
			sum += 4 * f(a + i * h);   // нечётные индексы — коэффициент 4
		}
	}
	return sum * h / 3.0;
}

// Метод Гаусса (квадратурные формулы для n = 4 или n = 8 узлов)
double gauss_quadrature(double a, double b, int n) {
	double integral = 0.0;
	if (n == 4) {
		// Узлы (t) и веса (w) для 4-точечной квадратуры
		double t[] = { 0.861136311594052, -0.861136311594052, 0.339981043584856, -0.339981043584856 };
		double w[] = { 0.347854845137454, 0.347854845137454, 0.652145154862546, 0.652145154862546 };

		// Преобразование от [-1, 1] к [a, b] и вычисление интеграла
		for (int i = 0; i < 4; ++i) {
			double x = (b - a) / 2 * t[i] + (b + a) / 2;
			integral += w[i] * f(x);
		}
	}
	else if (n == 8) {
		// Узлы и веса для 8-точечной квадратуры
		double t[] = { -0.96028986, -0.79666648, -0.52553241, -0.18343464, 0.18343464, 0.52553241, 0.79666648, 0.96028986 };
		double w[] = { 0.10122854, 0.22238103, 0.31370665, 0.36268378, 0.36268378, 0.31370665, 0.22238103, 0.10122854 };
		for (int i = 0; i < 8; ++i) {
			double x = (b - a) / 2 * t[i] + (b + a) / 2;
			integral += w[i] * f(x);
		}
	}
	return (b - a) / 2 * integral; // умножение на (b - a)/2 по формуле Гаусса
}

// Первообразная функции f(x): F(x) = 0.5 * arctan(x / 2)
double primitive(double x) {
	return 0.5 * atan(x / 2);
}

// Точное значение интеграла как разность первообразных
double integral(double a, double b) {
	return primitive(b) - primitive(a);  
}

int main() {
	setlocale(LC_ALL, "rus"); // установка русской локали для вывода на русском (может не работать в некоторых IDE)

	// Задание границ интегрирования
	double a = 2;
	double b = 2 * sqrt(3); // ≈ 3.464

	// Количество разбиений
	int n1 = 4;
	int n2 = 8;

	// Точное значение интеграла
	double Y = integral(a, b);

	// Вычисления методами
	double Ytrap4 = trapezoidal(a, b, n1);
	double Ytrap8 = trapezoidal(a, b, n2);

	double Ysim4 = simpson(a, b, n1);
	double Ysim8 = simpson(a, b, n2);

	double Ygauss4 = gauss_quadrature(a, b, n1);
	double Ygauss8 = gauss_quadrature(a, b, n2);

	// Настройка вывода: фиксированное количество знаков после запятой
	cout << fixed << setprecision(20);

	// Заголовок таблицы
	printf("n          Y           Yтрап       |Yтрап-Y|       Yсим              |Yсим-Y|               Yгаус       |Yгаус-Y| \n");

	// Вывод результатов для n1
	printf("%d      %f      %f      %f      %f      %.20f     %f      %f \n",
		n1, Y, Ytrap4, fabs(Ytrap4 - Y), Ysim4, fabs(Ysim4 - Y), Ygauss4, fabs(Ygauss4 - Y));

	// Вывод результатов для n2
	printf("%d      %f      %f      %f      %f      %.20f     %f      %f \n",
		n2, Y, Ytrap8, fabs(Ytrap8 - Y), Ysim8, fabs(Ysim8 - Y), Ygauss8, fabs(Ygauss8 - Y));

	return 0;
}
