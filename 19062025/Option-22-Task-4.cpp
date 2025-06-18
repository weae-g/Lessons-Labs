#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int N = 7;

int main() {
    int A[N][N] = {
        {230, 321, 432, 442, 533, 621, 320},
        {334, 219, 673, 651, 344, 762, 224},
        {456, 776, 443, 622, 632, 511, 299},
        {877, 446, 840, 332, 542, 631, 761},
        {432, 112, 532, 762, 544, 226, 331},
        {633, 422, 773, 533, 721, 652, 567},
        {238, 232, 645, 761, 354, 631, 562}
    };

    vector<int> cities;
    for (int i = 1; i < N; ++i)
        cities.push_back(i);  // исключаем 0, стартовый город

    int minCost = numeric_limits<int>::max();
    vector<int> bestRoute;

    do {
        int cost = 0;
        int prev = 0;
        for (int i = 0; i < cities.size(); ++i) {
            cost += A[prev][cities[i]];
            prev = cities[i];
        }
        cost += A[prev][0];  // возвращение в стартовый город

        if (cost < minCost) {
            minCost = cost;
            bestRoute = cities;
        }
    } while (next_permutation(cities.begin(), cities.end()));

    // Вывод лучшего маршрута
    cout << "Минимальный маршрут: 0 ";
    for (int city : bestRoute)
        cout << "-> " << city << " ";
    cout << "-> 0" << endl;

    cout << "Минимальная стоимость маршрута: " << minCost << endl;

    return 0;
}
