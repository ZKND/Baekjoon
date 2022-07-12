#include<iostream>
#include<string>


int main()
{
    int T = 0, cnt = 0;
    std::cin >> T;

    std::string input;

    for(int i = 0; i < T; i++)
    {
        cnt = 0;
        std::cin >> input;
        for(const auto& str : input)
        {
            if(str == '(') cnt++;
            else if(str == ')') cnt--;

            if(cnt<0) break;
        }
        if(cnt == 0) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}