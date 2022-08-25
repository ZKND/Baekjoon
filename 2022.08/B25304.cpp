#include<iostream>

int main()
{
    int total, type, sum = 0;

    std::cin >> total >> type;

    for(int i = 0; i < type; i++)
    {
        int a, b;
        std::cin >> a >> b;
        sum += (a*b);
    }

    sum == total ? std::cout << "Yes" : std::cout << "No";
}