#include <iostream>
using namespace std;

// Функция для поиска минимального элемента в части массива с индексами от start до end включительно
int findMin(const int arr[], int start, int end) {
    int minVal = arr[start];
    for (int i = start + 1; i <= end; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int main() {
    const int size = 12;
    int X[size];

    cout << "Введите 12 целых чисел массива X:\n";
    for (int i = 0; i < size; ++i) {
        cin >> X[i];
    }

    int minFirstPart = findMin(X, 0, 4);
    int minSecondPart = findMin(X, 5, 11);

    int result = minFirstPart + minSecondPart;

    cout << "min(X[0..4]) + min(X[5..11]) = " << result << endl;

    return 0;
}
