#include <iostream>
#include <limits>
using namespace std;

int main() {
    double number;
    double minVal = numeric_limits<double>::max();
    double maxVal = numeric_limits<double>::lowest();

    cout << "Введите вещественные числа (999 - конец ввода):\n";

    while (true) {
        cin >> number;

        if (number == 999)
            break;

        if (number < minVal) minVal = number;
        if (number > maxVal) maxVal = number;
    }

    if (minVal == numeric_limits<double>::max()) {
        cout << "Не введено ни одного числа до 999.\n";
    } else {
        double difference = maxVal - minVal;
        cout << "Максимум: " << maxVal << ", минимум: " << minVal << endl;
        cout << "Разность между наибольшим и наименьшим: " << difference << endl;
    }

    return 0;
}
