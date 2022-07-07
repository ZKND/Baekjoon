#include<iostream>
#include<string>
#include<algorithm>

bool descend(int a, int b)
{
    return a > b;
}

int main()
{
    int N = 0;
    std::cin >> N;
    std::string num = std::to_string(N);

    std::sort(num.begin(),num.end(), descend);

    for(const auto& string : num)
    {
        std::cout << string;
    }
}