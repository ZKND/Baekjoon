#include<iostream>
#include<vector>
#include<queue>

#define vector std::vector
#define MULTI tmp.first * 2
#define ADD1 (tmp.first * 10) + 1

std::queue<std::pair<long long, long long>> Q;

long long A, B;

void BFS(int A)
{
    Q.push({A, 1});

    while(!Q.empty())
    {
        auto tmp = Q.front();
        Q.pop();
        if(tmp.first > B)
            continue;
        if (MULTI == B || ADD1 == B)
        {
            std::cout << tmp.second + 1;
            return;
        }
        else
        {
            Q.push({MULTI, tmp.second + 1});
            Q.push({ADD1, tmp.second + 1});
        }
    }
    if(Q.empty())
        std::cout << "-1";
}

int main()
{
    std::cin >> A >> B;

    BFS(A);
}
