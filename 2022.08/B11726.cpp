#include<iostream>
#include<vector>

std::vector<int> dp(3);
int n;

void DP()
{

    for(int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;   
    }
}

int main()
{
    dp[1] = 1;
    dp[2] = 2;
    std::cin >> n;
    if (n > 2)
    {
        dp.resize(n + 1);
        DP();
    }

    std::cout << dp[n];
}