#include<iostream>

int main()
{
    long long A, B;

    std::cin >> A >> B;

    long long answer = (A + B) * (A-B);

    std::cout << answer;

}