#include<iostream>
#include<string>

int main()
{
    int T;
    std::cin >> T;
    std::string input;

    for(int i = 0; i < T; i++)
    {
        std::cin >> input;
        std::cout << input.front() << input.back() << "\n";
    }
}