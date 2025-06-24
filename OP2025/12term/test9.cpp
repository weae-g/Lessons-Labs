#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Введите строку (окончание ввода — перевод строки):\n";
    string line;
    getline(cin, line);

    bool hasAdjacentDuplicates = false;

    for (size_t i = 1; i < line.size(); ++i) {
        if (line[i] == line[i - 1]) {
            hasAdjacentDuplicates = true;
            break;
        }
    }

    if (hasAdjacentDuplicates) {
        cout << "В строке есть одинаковые соседние символы.\n";
    } else {
        cout << "Одинаковых соседних символов нет.\n";
    }

    return 0;
}
