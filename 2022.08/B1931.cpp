#include<iostream>
#include<vector>
#include<algorithm>

#define vector std::vector

int N, answer = 0;
vector<std::pair<int, int>> time;

bool compare(std::pair<int, int> A, std::pair<int, int> B)
{
    if(A.second == B.second)
    {
        return A.first < B.first;
    }
    return A.second < B.second;
}

int main()
{

    std::cin >> N;
    int input1, input2;
    for (int i = 0; i < N; i++)
    {
        std::cin >> input1 >> input2;

        time.push_back({input1, input2});        
    }
    std::sort(time.begin(), time.end(), compare);

    answer = 1;
    int tmp = time[0].second;
    for(int i = 1; i < N; i++)
    {
        if(time[i].first >= tmp)
        {
            answer++;
            tmp = time[i].second;
        }

    }
    std::cout << answer;
}