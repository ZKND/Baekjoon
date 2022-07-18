#include <iostream>
#include <vector>

void check(std::vector<std::vector<int>>& field, int i, int j, int& K)
{
    field[i][j] = 0;
    K--;

    if(j+1 < field[0].size() && field[i][j+1] == 1)check(field, i, j+1, K);
    if(i+1 < field.size() && field[i+1][j] == 1)check(field, i+1, j, K);
    if(j-1 >=0 && field[i][j-1] == 1) check(field, i, j-1, K);
    if(i-1 >=0 && field[i-1][j] == 1) check(field, i-1, j, K);

    return;
}

int main()
{
    int T = 0, W = 0, H = 0, K = 0, worm = 0, inputW, inputH;
    //  횟수,  너비,   높이,   배추수
    std::cin >> T;

    for (int l = 0; l < T; l++)
    {
        worm = 0;
        std::cin >> W >> H >> K;        // 가로, 세로, 배추
        std::vector<std::vector<int>> field(H, std::vector<int>(W, 0));
        for (int i = 0; i < K; i++)
        {
            std::cin >> inputW >> inputH;
            field[inputH][inputW] = 1;
        }
        /*
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                std::cout << field[i][j] << " ";
            }
            std::cout << "\n";
        }
        */

        for(int i = 0; i < H; i ++)
        {
            for(int j = 0; j < W; j++)
            {
                if(field[i][j] == 1)
                {
                    worm++;
                    field[i][j] = 0;
                    K--;

                    if(j+1 < field[0].size() && field[i][j+1] == 1) check(field, i, j+1, K);
                    if(i+1 < field.size() && field[i+1][j] == 1) check(field, i+1, j, K);
                }
            }            
            if(K == 0) break;
        }
        std::cout << worm << "\n";
    }
}