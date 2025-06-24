#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    cout << "Введите текст, оканчивающийся точкой:\n";

    string line;
    getline(cin, line);  // читаем всю строку целиком

    // Проверим, что строка оканчивается точкой
    if (line.empty() || line.back() != '.') {
        cout << "Текст должен оканчиваться точкой.\n";
        return 1;
    }

    // Уберём точку в конце, чтобы не мешала при разбиении на слова
    line.pop_back();

    stringstream ss(line);
    string word;
    int count = 0;

    while (ss >> word) {
        // Проверяем первый символ слова
        if (!word.empty()) {
            char first = word[0];
            // Если буква к или К (русская кириллическая)
            if (first == 'k' || first == 'K') {
                count++;
            }
        }
    }

    cout << "Количество слов, начинающихся с буквы 'к': " << count << "\n";

    return 0;
}
