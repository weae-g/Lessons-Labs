#include <iostream>
using namespace std;

bool isLatinLetter(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int main() {
    int n;
    cout << "Введите количество символов: ";
    cin >> n;

    char ch;
    bool found = false;

    cout << "Введите " << n << " символов:\n";

    for (int i = 0; i < n; ++i) {
        cin >> ch;
        if (isLatinLetter(ch)) {
            found = true;
        }
    }

    if (found) {
        cout << "В тексте есть латинские буквы.\n";
    } else {
        cout << "В тексте НЕТ латинских букв.\n";
    }

    return 0;
}
