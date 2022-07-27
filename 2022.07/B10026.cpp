#include<iostream>
#include<vector>

#define vector std::vector

vector<vector<char>> grid;
vector<vector<bool>> visited;

int N;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

bool isInside(int i, int j) { return (i >= 0 && i < N && j >= 0 && j < N); }

void DFS(int i, int j)
{
    visited[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int i2 = i + di[k];
        int j2 = j + dj[k];
        if (isInside(i2, j2) && grid[i2][j2] == grid[i][j] && !visited[i2][j2])
        {
            DFS(i2, j2);
        }
    }
}

int main()
{
    std::cin >> N;
    int ans1 = 0, ans2 = 0;

    grid.resize(N, vector<char>(N));
    visited.resize(N, vector<bool>(N, false));

    for(int i = 0; i < N; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        for(int j = 0; j < N; j++)
        {
            grid[i][j] = tmp[j];
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(!visited[i][j])
            {
                ans1++;
                DFS(i,j);
            }
        }
    }

    visited.assign(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(grid[i][j] == 'G') grid[i][j] = 'R';
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(!visited[i][j])
            {
                ans2++;
                DFS(i,j);
            }
        }
    }

    std::cout << ans1 << " " << ans2;
    
    return 0;
}