#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cout << "Введите строку (не более 80 символов, заканчивающуюся точкой):\n";
    std::getline(std::cin, str);

    if (str.length() > 80 || str.back() != '.') {
        std::cout << "Ошибка: строка должна быть не длиннее 80 символов и заканчиваться точкой.\n";
        return 1;
    }

    int digits[10] = {0}; // массив для подсчёта каждой цифры от 0 до 9

    for (char ch : str) {
        if (ch >= '0' && ch <= '9') {
            digits[ch - '0']++;
        }
    }

    std::cout << "\nЧастота появления цифр:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << i << " : " << digits[i] << " раз(а)\n";
    }

    return 0;
}
