#include <iostream>
using namespace std;

int main() {
    unsigned int n;
    double sum = 0.0;

    cout << "Введите количество чисел (n): ";
    cin >> n;

    cout << "Введите " << n << " действительных чисел:\n";
    for (unsigned int i = 0; i < n; ++i) {
        double Ai;
        cin >> Ai;

        if (Ai > 0) {
            sum += Ai;
        }
    }

    double result = 2 * sum;
    cout << "Удвоенная сумма положительных членов: " << result << endl;

    return 0;
}
