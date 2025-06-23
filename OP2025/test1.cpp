#include <iostream>
#include <cmath>

int main() {
    std::cout << "Enter x:\n";
    double x;
    std::cin >> x;

    double exp_val = std::exp(-x);
    std::cout << "exp(-x) = " << exp_val << "\n";

    // Вычисление суммы ряда Тейлора для exp(-x)
    x = -x;
    double s = 1.0;
    double current = 1.0;

    for (int i = 1; std::fabs(current) >= 0.0001; ++i) {
        current *= x / i;
        s += current;
    }

    std::cout << "Sum of series = " << s << "\n";

    return 0;
}
