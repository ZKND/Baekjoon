#include<iostream>
#include<vector>

#define vector std::vector

vector<vector<int>> board;
int zero = 0, minus = 0, plus = 0;

bool check(int x, int y, int size)
{
    bool chk = true;
    int tmp = board[x][y];

    for(int i = x; i < x + size; i++)
    {
        for(int j = y; j < y + size; j++)
        {
            if(board[i][j] != tmp)
            {
                return false;
            }
        }
    }

    if(chk)
    {
        switch(tmp)
        {
            case -1:
                minus++;
                break;
            case 0 :
                zero++;
                break;
            case 1 :
                plus++;
                break;
        }
    }

    return chk;    
}

void cut(int x, int y, int n)
{
    if(check(x, y, n))
        return;

    int tmp = n / 3;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cut(x + tmp*i, y + tmp*j, tmp);
        }
    }
}

int main()
{
    int N;
    std::cin >> N;
    board.assign(N, vector<int>(N));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cin >> board[i][j];
        }
    }


    cut(0,0,N);

    


    std::cout << minus << "\n";
    std::cout << zero << "\n";
    std::cout << plus << "\n";
}
