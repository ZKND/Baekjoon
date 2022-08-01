#include<queue>
#include<iostream>

std::priority_queue<int, std::vector<int>, std::greater<int>> PQ;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N, cmd;

    std::cin >> N;

    for(int i = 0; i < N; i++)
    {
        std::cin >> cmd;
        if(cmd == 0 && PQ.empty())
            std::cout << "0\n";
        else if (cmd == 0)
        {
            std::cout << PQ.top() << "\n";
            PQ.pop();
        }
        else if (cmd >= 1)
        {
            PQ.push(cmd);
        }
    }    
}