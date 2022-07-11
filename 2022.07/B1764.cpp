#include<iostream>
#include<string>
#include<set>

int main()
{
    int N = 0, M = 0;

    std::cin >> N >> M;

    std::string temp;
    std::set<std::string> Name1;
    std::set<std::string> result;

    for(int i = 0; i < N; i++)
    {
        std::cin >> temp;
        Name1.insert(temp);
    }

    for(int i = 0; i < M; i++)
    {
        std::cin >> temp;
        if(Name1.find(temp) != Name1.end())
        {
            result.insert(temp);
        }
    }

    std::cout << result.size() << "\n";

    for(const auto& answer : result)
    {
        std::cout << answer << "\n";
    }

}