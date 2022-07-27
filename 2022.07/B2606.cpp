#include <iostream>
#include <vector>

std::vector<bool> isVirus;
std::vector<std::vector<int>> node;
int answer = 0;

void DFS(int N)
{
    if (N != 1)
    {
        isVirus[N] = true;
        answer++;
    }

    for (int i = 0; i < node[N].size(); i++)
    {
        if (!isVirus[node[N][i]])
            DFS(node[N][i]);
    }
}

int main()
{
    int N, M;

    std::cin >> N >> M;
    isVirus.resize(N + 1, false);
    node.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int n1, n2;
        std::cin >> n1 >> n2;
        node[n1].push_back(n2);
        node[n2].push_back(n1);
    }

    isVirus[1] = true;

    DFS(1);

    std::cout<< answer;
}