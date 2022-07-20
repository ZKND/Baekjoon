#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

#define VVINT std::vector<std::vector<int>>

std::vector<bool> visited;


int BFS(int start, VVINT edges, int N, int end)
{
    int cnt = 0, tmp1 = 0, tmp2 = 0;
    std::queue<int> bfsQ;
    bfsQ.push(start);
    visited[start] = true;

    while(!bfsQ.empty())
    {
        cnt++;
        int Qsize = bfsQ.size();
        for (int i = 0; i < Qsize; i++)
        {
            for (int edge : edges[bfsQ.front()])
            {
                if (edge == end)
                    return cnt;
                else if (!visited[edge])
                {
                    bfsQ.push(edge);
                    visited[edge] = true;
                }
            }
            bfsQ.pop();
        }
    }
}

int main()
{
    int N = 0, M = 0;
    std::cin >> N >> M;
    VVINT edges;

    edges.resize(N+1);

    for(int i = 0; i < M; i++)
    {
        int tmp1, tmp2;
        std::cin >> tmp1 >> tmp2;

        edges[tmp1].push_back(tmp2);
        edges[tmp2].push_back(tmp1);
    }
    for(std::vector<int>& listTmp : edges)
    {
        sort(listTmp.begin(), listTmp.end());
    }

    int min = -1, who = -1;

    for(int i = 1; i <= N; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= N; j++)
        {
            if(i == j) continue;

            visited.assign(N+1, false);
            int tmp = BFS(i, edges, N, j);
            cnt += tmp;
        }
        if (cnt < min || min == -1)
        {
            min = cnt;
            who = i;
        }
    }
    std::cout << who;
}