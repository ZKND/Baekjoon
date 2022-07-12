#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int N = 0, M = 0, tmp;

    std::vector<int> listN(100000); //, listM;

    std::cin >> N;
    for(int i = 0; i < N; i++)
    {
        std::cin >> listN[i];
        /*
        std::cin >> tmp;
        listN.push_back(tmp);
        */
    }

    std::sort(listN.begin(), listN.begin() + N);

    std::cin >> M;
    
    for(int i = 0; i < M; i++)
    {
        std::cin >> tmp;
        // listM.push_back(tmp);

        if(std::binary_search(listN.begin(), listN.begin() + N, tmp)) std::cout << 1 << "\n";
        else std::cout << 0 << "\n";
    }
}