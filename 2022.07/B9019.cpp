#include <queue>
#include <iostream>
#include <string>

int a, b;
std::vector<bool> visited(10000);

void bfs()
{
    std::queue<std::pair<int, std::string>> q;
    q.push(std::make_pair(a, ""));
    visited[a] = true;

    while (!q.empty())
    {
        int cur_num = q.front().first;
        std::string cur_op = q.front().second;
        q.pop();

        if (cur_num == b)
        {
            std::cout << cur_op << '\n';
            return;
        }

        int D, S, L, R, temp;
        
        D = (cur_num * 2) % 10000;
        if (!visited[D])
        {
            visited[D] = true;
            q.push(std::make_pair(D, cur_op + "D"));
        }

        S = cur_num - 1 < 0 ? 9999 : cur_num - 1;
        if (!visited[S])
        {
            visited[S] = true;
            q.push(std::make_pair(S, cur_op + "S"));
        }

        L = (cur_num % 1000) * 10 + (cur_num / 1000);
        if (!visited[L])
        {
            visited[L] = true;
            q.push(std::make_pair(L, cur_op + "L"));
        }

        R = cur_num / 10 + (cur_num % 10) * 1000;
        if (!visited[R])
        {
            visited[R] = true;
            q.push(std::make_pair(R, cur_op + "R"));
        }
    }
}

int main()
{

    int T;
    std::cin >> T;

    while (T--)
    {
        std::cin >> a >> b;
        visited.assign(10000, false); // 초기화
        bfs();
    }

    return 0;
}