#include<iostream>
#include<vector>
#include<algorithm>

#define vector std::vector

vector<vector<int>> price;
int N;

int main()
{
    std::cin >> N;

    price.assign(N+1,vector<int>(3));
    
    price[0][0] = 0;
    price[0][1] = 0;
    price[0][2] = 0;

    int R, G, B;
    for(int i = 1; i <= N; i++)
    {
        std::cin >> R >> G >> B;
        price[i][0] = std::min(price[i-1][1], price[i-1][2]) + R;
        price[i][1] = std::min(price[i-1][0], price[i-1][2]) + G;
        price[i][2] = std::min(price[i-1][0], price[i-1][1]) + B;        
    }

    std::cout << std::min(price[N][0], std::min(price[N][1], price[N][2]));
}