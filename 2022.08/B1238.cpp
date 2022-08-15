#include <iostream>
#include <vector>
#include <queue>
//#include <functional>
#include <algorithm>

#define vector std::vector
#define pairII std::pair<int, int>
#define INF 1000000

int N, M, X;

bool cmp(int A, int B)
{
    return A > B;
}
struct Compare
{
    bool operator()(pairII A, pairII B)
    {
        if (A.first == B.first)
        {
            return A.second > B.second;
        }
        else
            return A.first > B.first;
    }
};

std::priority_queue<pairII, vector<pairII>, Compare> PQ;

vector<bool> visited;

vector<vector<pairII>> edges;

vector<int> XtoHome;
vector<int> HometoX;

void Dijkstra(int start)
{
    XtoHome.assign(N + 1, INF);
    visited.assign(N + 1, false);
    XtoHome[start] = 0;

    PQ.push({0, start});

    while (!PQ.empty())
    {
        pairII tmp = PQ.top();
        PQ.pop();
        visited[tmp.second] = true;

        for (int i = 0; i < edges[tmp.second].size(); i++)
        {
            pairII next = edges[tmp.second][i];
            if (visited[next.second])
            {
                continue;
            }

            // 현재 위치가 tmp, edges[tmp.second][i] 값이 연결된 정점의 정보
            int NEW = XtoHome[tmp.second] + next.first;
            int PREV = XtoHome[next.second];

            if (NEW < PREV)
                XtoHome[next.second] = NEW;

            PQ.push(std::make_pair(NEW, next.second));

            // {1, 2} {2, 3} {3, 4} {시간, 지점}
        }
    }
}

int main()
{
    std::cin >> N >> M >> X;

    edges.assign(N + 1, vector<pairII>());
    visited.assign(N + 1, false);
    vector<int> answer(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int from, to, time;
        std::cin >> from >> to >> time;
        edges[from].push_back(std::make_pair(time, to));
    }

    Dijkstra(X);

    for (int i = 1; i <= N; i++)
    {
        //std::cout << XtoHome[i] << "\n";
        answer[i] += XtoHome[i];
    }

    for (int i = 1; i <= N; i++)
    {
        if(i==X)
            continue;
        Dijkstra(i);
        answer[i] += XtoHome[X];
    }
    std::sort(answer.begin(), answer.end(), cmp);
    std::cout << answer[0];

}
