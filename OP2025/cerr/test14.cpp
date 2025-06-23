#include <iostream>
#include <cstdlib> // для std::abs
using namespace std;

// Функция вычисления произведения элементов массива,
// модуль которых меньше заданного числа threshold
int productIfAbsLessThan(const int arr[], int n, int threshold) {
    int product = 1;
    bool found = false; // флаг, чтобы проверить, были ли подходящие элементы
    for (int i = 0; i < n; ++i) {
        if (abs(arr[i]) < threshold) {
            product *= arr[i];
            found = true;
        }
    }
    if (!found) {
        // Если нет ни одного подходящего элемента, можно вернуть 0 или 1,
        // тут решите, что логичнее. Я верну 0 — произведение пустого множества
        return 0;
    }
    return product;
}

int main() {
    int n;
    cout << "Введите размер массивов (n ≤ 10): ";
    cin >> n;
    if (n <= 0 || n > 10) {
        cout << "Ошибка: n должно быть от 1 до 10.\n";
        return 1;
    }

    int arr1[10], arr2[10];
    cout << "Введите элементы первого массива:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    cout << "Введите элементы второго массива:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr2[i];
    }

    int threshold;
    cout << "Введите пороговое число (threshold): ";
    cin >> threshold;

    int prod1 = productIfAbsLessThan(arr1, n, threshold);
    int prod2 = productIfAbsLessThan(arr2, n, threshold);

    cout << "Произведение элементов первого массива по модулю меньше " << threshold << ": " << prod1 << endl;
    cout << "Произведение элементов второго массива по модулю меньше " << threshold << ": " << prod2 << endl;

    return 0;
}
