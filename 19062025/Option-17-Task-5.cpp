// kombinacii.cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// ---------- 1. Перестановки слова ----------
void generatePermutations(string word) {
    sort(word.begin(), word.end());  // Сортируем буквы для корректной генерации перестановок
    cout << "Перестановки слова '" << word << "':\n";
    do {
        cout << word << "\n";  // Выводим текущую перестановку
    } while (next_permutation(word.begin(), word.end()));  // Получаем следующую перестановку
    cout << "-------------------------\n";
}

// ---------- 2. Сочетания без повторений ----------
// Рекурсивная функция для генерации сочетаний по k элементов без повторений
void combinationsNoRepeat(const vector<char>& A, int k, vector<char>& current, int index) {
    if (current.size() == k) {
        for (char c : current) cout << c << " ";  // Печать текущей комбинации
        cout << endl;
        return;
    }

    for (int i = index; i < A.size(); ++i) {
        current.push_back(A[i]);                      // Добавляем элемент
        combinationsNoRepeat(A, k, current, i + 1);   // Рекурсивно выбираем следующий
        current.pop_back();                           // Удаляем последний элемент (шаг назад)
    }
}

// ---------- 3. Сочетания с повторениями и ограничениями ----------
// Генерация всех сочетаний длины k из элементов с ограничениями повторения
void combinationsWithLimits(map<char, int>& limits, int k, vector<pair<char, int>>& current, int depth, int sum) {
    if (sum == k) {
        // Если сумма равна k, то выводим сочетание
        for (const auto& p : current) {
            for (int i = 0; i < p.second; ++i)
                cout << p.first;
        }
        cout << endl;
        return;
    }
    if (depth == limits.size() || sum > k) return;  // Прекращаем, если дошли до конца или перебор

    // Получаем текущую букву и её максимум
    auto it = next(limits.begin(), depth);
    char letter = it->first;
    int maxCount = it->second;

    for (int cnt = 0; cnt <= min(maxCount, k - sum); ++cnt) {
        current.push_back({letter, cnt});  // Добавляем букву с повторением cnt раз
        combinationsWithLimits(limits, k, current, depth + 1, sum + cnt);  // Переходим к следующей
        current.pop_back();  // Шаг назад
    }
}

// ---------- MAIN ----------
int main() {
    setlocale(LC_ALL, "Russian");


    // 1) Перестановки слов
    string wordA = "пряник";
    string wordB = "глагол";
    generatePermutations(wordA);  // Все перестановки "пряник"
    generatePermutations(wordB);  // Все перестановки "глагол"

    // 2) Сочетания по 4 из множества A = {a, b, c, d, e, f, g}
    vector<char> setA = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    vector<char> current;
    cout << "Сочетания по 4 без повторений из A:\n";
    combinationsNoRepeat(setA, 4, current, 0);

    // 3) Сочетания с ограничениями из B = {a, b, c, d}, k = 4
    map<char, int> limitsB = {{'a', 3}, {'b', 2}, {'c', 3}, {'d', 4}};
    vector<pair<char, int>> currentComb;
    cout << "\nСочетания с повторениями (ограниченные) из B по 4:\n";
    combinationsWithLimits(limitsB, 4, currentComb, 0, 0);

    // 4) Дополнительное задание — вариант 2
    cout << "\nСочетания без повторений из {a,b,c,e,f,g} по 6:\n";
    vector<char> setA2 = {'a', 'b', 'c', 'e', 'f', 'g'};
    vector<char> temp;
    combinationsNoRepeat(setA2, 6, temp, 0);

    // 5) Сочетания с ограничениями из {a,b,c,h}, k = 5
    cout << "\nСочетания с ограничениями из {a,b,c,h}, k=5:\n";
    map<char, int> limitsB2 = {{'a', 3}, {'b', 2}, {'c', 3}, {'h', 2}};
    vector<pair<char, int>> currentComb2;
    combinationsWithLimits(limitsB2, 5, currentComb2, 0, 0);

    return 0;
}
