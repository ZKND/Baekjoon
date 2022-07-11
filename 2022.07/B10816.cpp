#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N = 0, M = 0, input = -1;
    std::vector<int> Cards;

    std::cin >> N;

    for(int i = 0; i < N; i++)
    {
        std::cin >> input;
        Cards.push_back(input);
    }
    std::sort(Cards.begin(), Cards.end());

    std::cin >> M;
    for(int i = 0; i < M; i++)
    {
        std::cin >> input;
        std::cout << std::upper_bound(Cards.begin(), Cards.end(), input) - std::lower_bound(Cards.begin(), Cards.end(), input) << " ";
    }
}