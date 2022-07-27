#include <iostream>
#include <vector>

std::vector<std::vector<int>> node;
std::vector<bool> visited;

void DFS(int N)
{
    visited[N] = true;

    for (int i = 0; i < node[N].size(); i++)
    {
        if (!visited[node[N][i]])
            DFS(node[N][i]);
    }
}

int main()
{
    int N, M, answer = 0;

    std::cin >> N >> M;
    if (M == 0)
    {
        std::cout << N;
        return 0;
    }

    node.resize(N + 1);
    visited.resize(N + 1, false);

    int tmp1, tmp2;
    for (int i = 0; i < M; i++)
    {
        std::cin >> tmp1 >> tmp2;

        node[tmp1].push_back(tmp2);
        node[tmp2].push_back(tmp1);
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            answer++;
            DFS(i);
        }
    }

    std::cout << answer;
}