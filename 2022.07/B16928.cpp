#include<iostream>
#include<vector>
#include<queue>

#define vector std::vector

vector<int> board(101, -1);
vector<vector<int>> node(101);
vector<vector<int>> ladder(101);
std::queue<int> Q;


void BFS()
{
    int tmp;

    while(!Q.empty())
    {
        int from = Q.front();
        Q.pop();
        tmp = board[from] + 1;
        if (!ladder[from].empty())
        {
            for (int to : ladder[from])
            {
                if (board[to] > board[from] || board[to] == -1)
                {
                    board[to] = board[from];
                    Q.push(to);
                }
            }
        }
        else
        {
            for (int to : node[from])
            {
                if (board[to] > tmp || board[to] == -1)
                {
                    board[to] = tmp;
                    Q.push(to);
                }
            }
        }
    }
}

int main()
{
    int N, M;
    std::cin >> N >> M;

    board[1] = 0;

    for(int i = 1; i < 100; i++)
    {
        for(int j = i + 1; j < i + 7 && j <= 100; j++)
        {
            node[i].push_back(j);
        }
    }

    int from, to;

    for(int i = 0; i < N + M; i++)
    {
        std::cin >> from >> to;

        ladder[from].push_back(to);
    }

    Q.push(1);
    BFS();

    std::cout << board[100];

}
