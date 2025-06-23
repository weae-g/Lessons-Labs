#include <iostream>

// Проверка: сумма кубов от 1 до n == квадрат суммы от 1 до n
bool isItTrue(unsigned n)
{
    unsigned long long sum1 = 0, sum2 = 0;
    for (unsigned i = 1; i <= n; i++)
    {
        sum1 += static_cast<unsigned long long>(i) * i * i;
        sum2 += i;
    }
    return sum1 == sum2 * sum2;
}

int main()
{
    unsigned n;
    std::cout << "Enter a natural number n: ";
    std::cin >> n;

    if (isItTrue(n))
        std::cout << "The equality is TRUE for n = " << n << "\n";
    else
        std::cout << "The equality is FALSE for n = " << n << "\n";

    return 0;
}
