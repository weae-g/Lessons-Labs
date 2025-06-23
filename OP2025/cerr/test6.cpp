#include <iostream>
#include <string>
#include <locale>

int main() {
    // Установка локали для поддержки русских символов в консоли
    std::locale::global(std::locale(""));

    std::wstring str = L"Строка состоит из слов pазделенных пpобелами вывести самое длинное слово и его поpядковый номеp в исходной стpоке\n";

    int maxLength = 0;
    std::wstring longestWord;
    int wordNumber = 0;
    int longestWordNumber = 0;

    std::wstring currentWord;
    for (size_t i = 0; i < str.size(); ++i) {
        wchar_t ch = str[i];
        if (ch != L' ' && ch != L'\n') {
            currentWord += ch;
        } else {
            if (!currentWord.empty()) {
                ++wordNumber;
                if (currentWord.length() > static_cast<size_t>(maxLength)) {
                    maxLength = currentWord.length();
                    longestWord = currentWord;
                    longestWordNumber = wordNumber;
                }
                currentWord.clear();
            }
        }
    }

    std::wcout << L"Самое длинное слово: \"" << longestWord << L"\"\n";
    std::wcout << L"Порядковый номер слова: " << longestWordNumber << std::endl;

    return 0;
}
