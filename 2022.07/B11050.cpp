#include<iostream>

int fac(int num)
{
    if(num == 0) return 1;
    else if(num > 1) return num * fac(num-1);
    else return num;
}

int main()
{
    int N = 0, K = 0, ans = -1;

    std::cin >> N >> K;

    ans = fac(N) / (fac(K)*fac(N-K));
    
    std::cout << ans;
}