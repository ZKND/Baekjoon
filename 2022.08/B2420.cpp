#include<iostream>
//#include<cmath>

int main()
{
    long long N, M;
    std::cin >> N >> M;
    
    long long answer = N-M;
    /*
    if(answer < 0)
        answer * (-1);
    */

    std::cout << llabs(answer);
}