#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Введите скобочное выражение, оканчивающееся точкой с запятой:\n";

    string expr;
    getline(cin, expr);

    // Проверим, что выражение заканчивается точкой с запятой
    if (expr.empty() || expr.back() != ';') {
        cout << "Выражение должно оканчиваться точкой с запятой.\n";
        return 1;
    }

    int currentLevel = 0;  // текущий уровень вложенности
    int maxLevel = 0;      // максимальный уровень вложенности

    for (char ch : expr) {
        if (ch == '(') {
            currentLevel++;
            if (currentLevel > maxLevel) {
                maxLevel = currentLevel;
            }
        } else if (ch == ')') {
            currentLevel--;
            if (currentLevel < 0) {
                cout << "Ошибка: закрывающая скобка без соответствующей открывающей.\n";
                return 1;
            }
        }
    }

    if (currentLevel != 0) {
        cout << "Ошибка: количество открывающих и закрывающих скобок не совпадает.\n";
        return 1;
    }

    cout << "Максимальный уровень вложенности скобок: " << maxLevel << "\n";

    return 0;
}
