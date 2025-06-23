#include <iostream>
#include <string>
#include <locale>
#include <cwctype> // для towupper

bool isVowel(wchar_t ch) {
    ch = towupper(ch); // сделать букву заглавной для упрощения
    return wcschr(L"АЕЁИОУЫЭЮЯAEIOUY", ch) != nullptr;
}

int main() {
    std::locale::global(std::locale(""));

    std::wstring str;
    std::wcout << L"Введите строку (не более 80 символов, заканчивающуюся точкой):\n";
    std::getline(std::wcin, str);

    if (str.length() > 80 || str.back() != L'.') {
        std::wcout << L"Ошибка: строка должна содержать не более 80 символов и заканчиваться точкой.\n";
        return 1;
    }

    std::wcout << L"Результат:\n";
    for (wchar_t ch : str) {
        if (isVowel(ch)) {
            std::wcout << L'_';
        } else {
            std::wcout << ch;
        }
    }
    std::wcout << std::endl;

    return 0;
}
