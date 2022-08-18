#include<iostream>
#include<vector>
#include<queue>

#define vector std::vector
#define pairII std::pair<int, int>
#define INF 1000000

vector<vector<int>> edges;
vector<bool> visited;
vector<int> result;

int N, M, K, X;

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


void Dijkstra(int start)
{
    
    result.assign(N + 1, INF);
    std::priority_queue<pairII, vector<pairII>, Compare> PQ;
    visited.assign(N + 1, false);

    PQ.push(std::make_pair(0, start));
    result[start] = 0;

    while(!PQ.empty())
    {
        pairII tmp = PQ.top();
        PQ.pop();
        visited[tmp.second] = true;

        for(int i = 0; i < edges[tmp.second].size(); i++)
        {
            if(visited[edges[tmp.second][i]])
                continue;
            

            int NEW = result[tmp.second] + 1;
            int PREV = result[edges[tmp.second][i]];
            if(NEW < PREV)
                result[edges[tmp.second][i]] = NEW;
            
            PQ.push(std::make_pair(NEW, edges[tmp.second][i]));
        }

    }
}

int main()
{
    std::cin >> N >> M >> K >> X;
    //도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X

    edges.assign(N + 1, vector<int>());

    for(int i = 0; i < M; i++)
    {
        int from, to;
        std::cin >> from >> to;

        edges[from].push_back(to);
    }

    Dijkstra(X);

    bool chk = false;
    for(int i = 1; i <= N; i++)
    {
        if(result[i] == K)
        {
            std::cout << i << "\n";
            chk = true;
        }
    }
    if(!chk)
        std::cout << "-1";
}