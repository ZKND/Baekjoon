#include<iostream>
#include<vector>

int main()
{
    int N, v, answer = 0;
    std::cin >> N;
    std::vector<int> numbers(N);

    for(int i = 0; i < N; i++)
    {
        std::cin >> numbers[i];
    }
    std::cin >> v;

    for(int number : numbers)
    {
        if(number == v)
            answer++;
    }

    std::cout << answer;

}