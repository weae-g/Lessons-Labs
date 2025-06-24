#include <iostream>
using namespace std;

int main() {
    int number;
    int count = 0;
    int sum = 0;

    cout << "Введите натуральные числа (0 - конец ввода):\n";

    while (true) {
        cin >> number;

        if (number == 0)
            break;

        if (number % 5 == 0 && number % 7 != 0) {
            count++;
            sum += number;
        }
    }

    cout << "Количество подходящих чисел: " << count << endl;
    cout << "Сумма подходящих чисел: " << sum << endl;

    return 0;
}
