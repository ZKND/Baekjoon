#include<iostream>
#include<queue>

int main()
{
    int N = 0;
    std::cin >> N;
    std::queue<int> list;
    for(int i = 0; i < N; i++)
    {
        list.push(i+1);
    }

    while(true)
    {
        if(list.size() == 1) break;
        list.pop();
        list.push(list.front());
        list.pop();
    }

    std::cout << list.front();
}