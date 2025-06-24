#include "stdafx.h"        // Предкомпилированный заголовок 

using namespace std;

int main() {
    double a, b, c;

    cout << "Введите стороны треугольника (a, b, c): ";
    cin >> a >> b >> c;

    // Проверка на существование треугольника
    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "Ошибка: треугольник с такими сторонами не существует.\n";
        return 1;
    }

    // Периметр
    double perimeter = a + b + c;
    cout << "Периметр треугольника: " << perimeter << endl;

    // Полупериметр
    double p = perimeter / 2;

    // Площадь по формуле Герона
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << "Площадь треугольника: " << area << endl;

    // Определение типа треугольника
    if (a == b && b == c) {
        cout << "Треугольник равносторонний.\n";
    } else if (a == b || b == c || a == c) {
        cout << "Треугольник равнобедренный.\n";
    } else {
        cout << "Треугольник разносторонний.\n";
    }

    return 0;
}
