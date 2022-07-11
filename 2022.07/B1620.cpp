#include<iostream>
#include<map>
#include<string>
#include<vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N = 0, M = 0, number = -1;
    std::string input;
    std::map<std::string,int> pokedex;
    std::vector<std::string> num;

    std::cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        
        std::cin >> input;
        pokedex.insert(std::pair<std::string, int>(input, i));
        /*
        pokedex.insert(std::make_pair(input, i));
        pokedex[input] = i;
        */
        num.push_back(input);
    }

    for(int i = 0; i < M; i++)
    {
        std::cin >> input;

        if(isdigit(input[0]))   // 번호 입력
        {
            number = std::stoi(input);
            std::cout << num[number - 1] << "\n";
        }
        else    // 이름 입력
        {
            std::cout << pokedex[input] << "\n";
        }
    }
}