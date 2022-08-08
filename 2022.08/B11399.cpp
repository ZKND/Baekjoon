#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> time(N);
    for(int i = 0; i < N; i++)
    {
        std::cin >> time[i];
    }

    std::sort(time.begin(), time.end());

    int sum = 0, answer = 0;
    for(int min : time)
    {
        sum += min;
        answer += sum;
    }

    std::cout << answer;

}