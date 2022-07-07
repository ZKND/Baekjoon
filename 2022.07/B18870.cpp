#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N = 0;
    std::cin >> N;    
    std::vector<int> Numbers(N,0);
    std::vector<int> Results(N,0);

    int temp;
    for(int i = 0; i < N; i++)
    {
        std::cin >> temp;
        Numbers[i] = temp;
        Results[i] = temp;
    }

    sort(Results.begin(), Results.end());
    Results.erase(unique(Results.begin(),Results.end()),Results.end());
    
    for(int i = 0; i < N; i ++)
    {
        // std::cout << std::find(Results.begin(), Results.end(), Numbers[i]) - Results.begin();
        std::cout << std::lower_bound(Results.begin(), Results.end(), Numbers[i]) - Results.begin();
        if(i != N -1) std::cout << " ";
    }
}