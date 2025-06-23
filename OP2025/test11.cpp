#include <iostream>
#include <limits>
using namespace std;

int main() {
    int n;
    cout << "Введите размер матрицы n (n < 7): ";
    cin >> n;

    if (n <= 0 || n >= 7) {
        cout << "Ошибка: n должно быть натуральным и меньше 7." << endl;
        return 1;
    }

    int matrix[7][7];  // выделяем максимальный размер

    cout << "Введите элементы матрицы " << n << "x" << n << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "Строка " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int sum = 0;
    int min_elem = numeric_limits<int>::max();

    // Побочная диагональ: индексы (i, n-1 - i)
    for (int i = 0; i < n; ++i) {
        int elem = matrix[i][n - 1 - i];
        sum += elem;
        if (elem < min_elem) {
            min_elem = elem;
        }
    }

    cout << "Сумма элементов побочной диагонали = " << sum << endl;
    cout << "Наименьший элемент побочной диагонали = " << min_elem << endl;

    return 0;
}
