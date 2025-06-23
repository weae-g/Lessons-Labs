#include <iostream>
using namespace std;

int main() {
    unsigned int n, count = 0;

    cout << "Введите количество чисел (n): ";
    cin >> n;

    cout << "Введите " << n << " натуральных чисел:\n";
    for (unsigned int i = 0; i < n; ++i) {
        unsigned int Ak;
        cin >> Ak;

        if (Ak % 3 == 0 && Ak % 5 != 0) {
            count++;
        }
    }

    cout << "Количество членов, кратных 3 и не кратных 5: " << count << endl;

    return 0;
}
