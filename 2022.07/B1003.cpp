#include<iostream>

int main()
{
    int T = 0, N = 0;

    std::pair<int, int> mem[41];

    mem[0] = {1, 0};
    mem[1] = {0, 1};
    for(int i = 2; i < 41; i++)
    {
        mem[i] = {mem[i-1].first + mem[i-2].first, mem[i-1].second + mem[i-2].second};
    }

    std::cin >> T;

    for(int i = 0; i < T; i++)
    {
        std::cin >> N;
        std::cout << mem[N].first << " " << mem[N].second << "\n";
    }

}