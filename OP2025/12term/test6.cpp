#include <iostream>
using namespace std;

int main() {
    char ch;
    int lineCount = 0;

    cout << "Введите текст (окончание ввода — символ #):\n";

    while (cin.get(ch)) {
        if (ch == '#') {
            break; // конец текста
        }
        if (ch == '\n') {
            lineCount++;
        }
    }

    cout << "Количество строк в тексте: " << lineCount << endl;

    return 0;
}
