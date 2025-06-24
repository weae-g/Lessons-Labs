#include <iostream>
using namespace std;

int main() {
    char ch;
    int digitCount = 0;

    cout << "Введите текст (завершите ввод символом ';'):\n";

    while (cin.get(ch)) {
        if (ch == ';')
            break;

        if (ch >= '0' && ch <= '9') {
            digitCount++;
        }
    }

    cout << "Количество цифр в тексте: " << digitCount << endl;

    return 0;
}
