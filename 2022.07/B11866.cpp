#include<iostream>
#include<queue>

int main()
{
    std::queue<int> people;
    int N = 0, K = 0;
    std::cin >> N >> K;

    for(int i = 0; i < N; i++)
    {
        people.push(i+1);
    }

    std::cout << "<";
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < K - 1; j++)
        {
            people.push(people.front());
            people.pop();
        }
        std::cout << people.front();
        if(i != N - 1) std::cout << ", ";
        else std::cout << ">";
        people.pop();
    }
}