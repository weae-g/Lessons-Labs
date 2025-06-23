#include <iostream>
#include <string>
using namespace std;

// Функция подсчёта количества цифр в строке
int countDigits(const string& s) {
    int count = 0;
    for (char ch : s) {
        if (ch >= '0' && ch <= '9') {
            count++;
        }
    }
    return count;
}

int main() {
    string str1, str2;

    cout << "Введите первую строку (до 80 символов):\n";
    getline(cin, str1);
    if (str1.length() > 80) {
        cout << "Ошибка: строка слишком длинная.\n";
        return 1;
    }

    cout << "Введите вторую строку (до 80 символов):\n";
    getline(cin, str2);
    if (str2.length() > 80) {
        cout << "Ошибка: строка слишком длинная.\n";
        return 1;
    }

    int digits1 = countDigits(str1);
    int digits2 = countDigits(str2);

    cout << "Цифр в первой строке: " << digits1 << endl;
    cout << "Цифр во второй строке: " << digits2 << endl;

    if (digits1 > digits2) {
        cout << "В первой строке больше цифр.\n";
    } else if (digits2 > digits1) {
        cout << "Во второй строке больше цифр.\n";
    } else {
        cout << "В обеих строках одинаковое количество цифр.\n";
    }

    return 0;
}
