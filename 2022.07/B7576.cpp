#include<iostream>
#include<vector>
#include<queue>

std::vector<std::vector<int>> tomato;
std::vector<std::vector<int>> node;
std::queue<std::pair<int, int>> Q; 

int M, N;
int dn[] = {0, 0, 1, -1};
int dm[] = {-1, 1, 0, 0};

bool isInside(int n, int m)
{
    return (n >= 0 && n < N && m >= 0 && m < M);
}

void BFS()
{

    while(!Q.empty())
    {
        int n = Q.front().first;
        int m = Q.front().second;
        Q.pop();

        for(int i = 0; i < 4; i++)
        {
            int n2 = n + dn[i];
            int m2 = m + dm[i];

            if(isInside(n2, m2) && tomato[n2][m2] == 0)
            {
                tomato[n2][m2] = tomato[n][m] + 1;
                Q.push({n2, m2});
            }         
        }
    }
}


int main()
{
    int answer = 0;


    std::cin >> M >> N;

    tomato.resize(N,std::vector<int>(M));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            int tmp;
            std::cin >> tmp;
            tomato[i][j] = tmp;
            if(tmp == 1)
                Q.push({i, j});                
        }
    }

    BFS();

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(tomato[i][j] == 0)
            {
                std::cout << "-1";
                return 0;
            }
            
            if(answer < tomato[i][j])
                answer = tomato[i][j];
        }
    }

    std::cout << answer - 1;
}