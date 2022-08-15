#include<iostream>
#include<cmath>

int main()
{
    int sum = 0;
    int a[5];

    for(int i = 0; i < 5; i++)
    {
        std::cin >> a[i];
        sum += std::pow(a[i], 2);
    }

    std::cout << sum % 10;
}