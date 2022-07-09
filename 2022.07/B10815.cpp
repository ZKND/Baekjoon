#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    int N = 0, M = 0, Find = 0;

    std::cin >> N;
    std::vector<int> Cards(N);
    for(int i = 0; i < N; i++)
    {
        std::cin >> Cards[i];
    }
    
    std::sort(Cards.begin(), Cards.end());

    std::cin >> M;
    std::vector<int> Results(M);
    for(int i = 0; i < M; i++)
    {
        std::cin >> Find;
        if(std::binary_search(Cards.begin(),Cards.end(),Find)) Results[i] = 1;
        else Results[i] = 0;

    }

    for(int i = 0; i < M; i++)
    {
        if(i != M - 1) std::cout << Results[i] << " ";
        else std::cout << Results[i];
    }
}