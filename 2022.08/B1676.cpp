#include<iostream>

int main()
{
    int N, answer = 0;

    std::cin >> N;

    for(int i = 1; i <= N; i++)
    {
        int tmp = i;
        while(tmp % 5 == 0)
        {
            tmp /= 5;
            answer++;
        }
    }

    std::cout << answer;


    

}