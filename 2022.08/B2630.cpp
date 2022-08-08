#include<iostream>
#include<vector>

#define vector std::vector

vector<vector<int>> board;

int N, white = 0, blue = 0;

bool check(int fromI, int toI, int fromJ, int toJ)
{
    int tmp = board[fromI][fromJ];
    bool CHK = true;

    for(int i = fromI; i <= toI; i++)
    {
        for(int j = fromJ; j <= toJ; j++)
        {
            if(tmp != board[i][j])
            {
                CHK = false;
                break;
            }
        }
        if(!CHK)
            break;
    }

    if(CHK)
    {
        if(tmp == 0)
            white++;
        else if(tmp == 1)
            blue++;
    }
    return CHK;
}
void CUT(int fromI, int toI, int fromJ, int toJ)
{
    int halfI = (fromI + toI) / 2;
    int halfJ = (fromJ + toJ) / 2;

    if(!check(fromI, halfI, fromJ, halfJ))
    {
        CUT(fromI, halfI, fromJ, halfJ);        
    }
    if(!check(fromI, halfI, halfJ + 1, toJ))
    {
        CUT(fromI, halfI, halfJ + 1, toJ);
    }
    if(!check(halfI + 1, toI, fromJ, halfJ))
    {
        CUT(halfI + 1, toI, fromJ, halfJ);
    }
    if(!check(halfI + 1, toI, halfJ + 1, toJ))
    {
        CUT(halfI + 1, toI, halfJ + 1, toJ);
    }

    return;
}

int main()
{

    std::cin >> N;
    board.assign(N, vector<int>(N));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cin >> board[i][j];
        }
    }

    if(!check(0, N - 1, 0, N - 1))
        CUT(0, N - 1, 0, N - 1);

    std::cout << white << "\n" << blue;    
}