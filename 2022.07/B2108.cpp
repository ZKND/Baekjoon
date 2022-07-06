#include<iostream>
#include<vector>

int main()
{
    std::cout << std::fixed;
    std::cout.precision(0);

    int N = 0;  // N은 홀수이다.

    
    std::vector<int> counting(8001,0);

    int max = -4001, min = 4001, most = 0;

    double aver = 0, sum = 0;
    int mid = 0, mostInt = 0, range = 0;      // 평균, 중앙, 최빈, 범위
    
    std::cin >> N;
    int input;
    if(N == 1)
    {
        std::cin >> input;
        std::cout << input << "\n" << input << "\n" << input << "\n" << "0";
        return 0;
    }

    for(int i = 0; i < N; i++)
    {
        std::cin >> input;
        sum += input;
        counting[input + 4000]++;
        if(input > max) max = input;
        if(input < min) min = input;
    }
    aver = sum / N;
    if(aver > -1 && aver < 0) aver = 0;
    std::cout << aver << "\n";  // 평균

    bool found = false;
    bool ManyMost = false;
    int tempMost = 0, mostCnt = 0;
    int cnt = 0, test = (N / 2) + 1;
    for(int i = 0; i < 8001; i++)
    {
        cnt += counting[i];
        if(cnt >= test && !found)
        {
            mid = i;
            found = true;
        }
        if(counting[i] > tempMost)
        {
            mostInt = i;
            tempMost = counting[i];
            // ManyMost = false;
            mostCnt = 1;
        }
        else if(counting[i] == tempMost && mostCnt >= 2) mostCnt++;
        else if(counting[i] == tempMost)
        {
            mostCnt++;
            mostInt = i;
        }

    }
    std::cout << mid - 4000 << "\n";   // 중앙

    std::cout << mostInt - 4000 << "\n"; // 최빈

    range = max - min;
    std::cout << range << "\n"; // 범위 
}