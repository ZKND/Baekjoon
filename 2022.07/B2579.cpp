#include <iostream>
#include <vector>

int N;
std::vector<int> stair;
std::vector<int> dp;

int max(int a, int b)
{
    return a > b ? a : b;
}
void DP()
{
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);

    for (int i = 4; i <= N; i++)
    {
        dp[i] = max(dp[i - 2] + stair[i], stair[i] + stair[i - 1] + dp[i - 3]);
    }
}

int main()
{

    std::cin >> N;
    stair.resize(N + 1);
    dp.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        std::cin >> stair[i];
    }
    DP();

    std::cout << dp[N];
}