#include <iostream>
using namespace std;

int main() {
    unsigned long int N, M;
    unsigned int kol;

    cout << "N = ";
    cin >> N;

    // Если число 0 — считаем 1 цифру
    if (N == 0) {
        kol = 1;
    } else {
        // Начинаем с 1 цифры, затем делим на 10, пока результат больше 0
        for (M = N, kol = 0; M > 0; kol++, M /= 10);
    }

    cout << "kol = " << kol << endl;

    return 0;
}
