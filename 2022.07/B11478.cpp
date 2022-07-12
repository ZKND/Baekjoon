#include<iostream>
#include<string>
#include<set>

int main()
{
    std::string S, tmp = "";
    std::cin >> S;

    std::set<std::string> Set;

    for(int i = 0; i < S.size(); i++)
    {
        for(int j = i; j < S.size(); j++)
        {
            tmp += S[j];            
            Set.insert(tmp);
        }
        tmp = "";
    }

    std::cout << Set.size();
}