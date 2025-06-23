#include <iostream>
using namespace std;

int main() {
    const int rows = 4;
    const int cols = 5;
    int matrix[rows][cols];

    cout << "Введите элементы матрицы 4x5 (целые числа):\n";

    // Ввод матрицы
    for (int i = 0; i < rows; ++i) {
        cout << "Строка " << i+1 << ": ";
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Подсчёт суммы элементов каждой строки
    for (int i = 0; i < rows; ++i) {
        int sum = 0;
        for (int j = 0; j < cols; ++j) {
            sum += matrix[i][j];
        }
        cout << "Сумма элементов строки " << i+1 << " = " << sum << endl;
    }

    return 0;
}
