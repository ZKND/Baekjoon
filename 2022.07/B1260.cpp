#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

std::vector<bool> visit;
std::vector<int> edges[1001];

void DFS(int& ver)
{
    visit[ver] = true;
    std::cout << ver << " ";
    for(int i = 0; i < edges[ver].size(); i++)
    {
        if (!visit[edges[ver][i]]) DFS(edges[ver][i]);
    }
}
void BFS(const int& ver)
{
    std::queue<int> Q;
    Q.push(ver);
    visit[ver] = true;

    while(!Q.empty())
    {
        int front = Q.front();
        Q.pop();
        for(const int& num : edges[front])
        {
            if(!visit[num]) Q.push(num);
            visit[num] = true;
        }
        std::cout << front << " ";
    }
}

int main()
{
    int N = 0, M = 0, V;

    std::cin >> N >> M >> V;
    
    visit.assign(N, false);


    for(int i = 0; i < M; i++)
    {
        int tmp1, tmp2;
        std::cin >> tmp1 >> tmp2;
        edges[tmp1].push_back(tmp2);
        edges[tmp2].push_back(tmp1);
    }

    for(auto& sort : edges)
    {
        std::sort(sort.begin(), sort.end());
    }

    DFS(V);
    std::cout << "\n";
    visit.assign(1001,false);

    BFS(V);
}