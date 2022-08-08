#include<iostream>
#include<vector>

#define MAX 11

std::vector<int> dp(MAX);

void DP()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i < MAX; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T, input;
    std::cin >> T;

    DP();

    for (int i = 0; i < T; i++)
    {
        std::cin >> input;
        std::cout << dp[input] << "\n";
    }
}