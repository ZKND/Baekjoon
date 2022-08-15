#include<iostream>

int main()
{
    std::string str;

    std::cin >> str;

    for(auto& C : str)
    {
        if(isupper(C))
        {
            C = tolower(C);
        }
        else
            C = toupper(C);
    }

    std::cout << str;
}