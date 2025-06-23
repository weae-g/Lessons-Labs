#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;
    int n, a[MAX];

    cout << "Введите количество элементов (n <= 10): ";
    cin >> n;

    if (n < 1 || n > MAX) {
        cout << "Некорректное значение n.\n";
        return 1;
    }

    cout << "Введите " << n << " целых чисел:\n";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Сортировка методом последовательного нахождения минимума по убыванию
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        // Меняем местами минимум с последним элементом текущей области
        swap(a[minIndex], a[n - 1 - i]);
    }

    // Вывод отсортированного массива
    cout << "Массив, отсортированный по убыванию:\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
