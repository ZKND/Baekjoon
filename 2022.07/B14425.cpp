#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main()
{
    int N = 0, M = 0, cnt = 0;
    std::cin >> N >> M;
    std::vector<std::string> ListS(N);
    
    for(int i = 0; i < N; i++)  // O(N)
    {
        std::cin >> ListS[i];
    }

    std::string input;
    std::sort(ListS.begin(), ListS.end());
    for(int i = 0; i < M; i++)  // O(MlogM)
    {
        std::cin >> input;
        if(std::binary_search(ListS.begin(), ListS.end(), input)) cnt++;
    }
    
    std::cout << cnt;    
}