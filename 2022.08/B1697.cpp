#include<iostream>
#include<vector>
#include<queue>

#define vector std::vector

int start, end, MAX = 100001, MIN = 0;
vector<int> point(100001, -1);
std::queue<int> Q;

void BFS()
{
    Q.push(start);
    point[start] = 0;

    while(!Q.empty())
    {
        int tmp = Q.front();
        Q.pop();

        for(int next : {tmp + 1, tmp - 1, tmp * 2})
        {
            if(next <= MAX && next >= MIN && point[next] == -1)
            {
                Q.push(next);
                point[next] = point[tmp] + 1;
            }
            if (next == end)
                return;
        }
    }
}

int main()
{
    std::cin >> start >> end;

    BFS();

    std::cout << point[end];
}