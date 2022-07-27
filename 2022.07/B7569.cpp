#include<iostream>
#include<queue>
#include<tuple>

#define vector std::vector

vector<vector<vector<int>>> tomato;
std::queue<std::tuple<int,int,int>> Q;

int H, N, M;

bool isInside(int h, int n, int m)
{
    return (n >= 0 && n < N && m >= 0 && m < M && h >= 0 && h < H);
}

int dn[] = {0, 0, 0, 0, 1, -1};
int dm[] = {0, 0, 1, -1, 0, 0};
int dh[] = {1, -1, 0, 0, 0, 0};

void BFS()
{
    while(!Q.empty())
    {
        std::tuple<int,int,int> tmp = Q.front();
        int h = std::get<0>(tmp);
        int n = std::get<1>(tmp);
        int m = std::get<2>(tmp);
        Q.pop();
        
        for(int i = 0; i < 6; i++)
        {
            int h2 = dh[i] + h;
            int n2 = dn[i] + n;
            int m2 = dm[i] + m;

            if (isInside(h2, n2, m2) && tomato[h2][n2][m2] == 0)
            {
                tomato[h2][n2][m2] = tomato[h][n][m] + 1;
                Q.push({h2, n2, m2});
            }
        }
    }
}

int main()
{
    int answer = 0;
    std::cin >> M >> N >> H;

    tomato.resize(H, vector<vector<int>>(N, vector<int>(M)));

    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < M; k++)
            {
                int tmp;
                std::cin >> tmp;
                tomato[i][j][k] = tmp;
                if(tmp == 1)
                    Q.push({i, j, k});
            }
        }
    }

    BFS();

    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < M; k++)
            {
                if(tomato[i][j][k] == 0)
                {
                    std::cout << "-1";
                    return 0;
                }
                if(answer < tomato[i][j][k])
                {
                    answer = tomato[i][j][k];
                }                
            }
        }
    }

    std::cout << answer - 1;
}