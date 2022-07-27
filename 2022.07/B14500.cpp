#include<iostream>
#include<vector>

#define vector std::vector

int N, M, answer = 0;
vector<vector<int>> board;
vector<vector<bool>> visited;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

bool isInside(int i, int j) { return (i >= 0 && i < N && j >= 0 && j < M); }

void DFS(int i, int j, int sum = 0, int cnt = 0)
{
    visited[i][j] = true;
    sum += board[i][j];
    if (cnt == 3)
    {
        if (answer < sum)
            answer = sum;
        return;
    }

    for(int k = 0; k < 4; k++)
    {
        int i2 = i + di[k];
        int j2 = j + dj[k];
        if(isInside(i2, j2) && !visited[i2][j2])
        {
            DFS(i2, j2, sum, cnt + 1);
            visited[i2][j2] = false;
        }
    }
}
void case1(int r, int c)
{
	int sum = 0;
	sum = board[r][c] + board[r][c + 1] + board[r][c + 2] + board[r - 1][c + 1];
	if(answer < sum) answer = sum;
}

void case2(int r, int c)
{
	int sum = 0;
	sum = board[r][c] + board[r][c + 1] + board[r][c + 2] + board[r + 1][c + 1];
	if(answer < sum) answer = sum;
}

void case3(int r, int c)
{
	int sum = 0;
	sum = board[r][c] + board[r + 1][c] + board[r + 2][c] + board[r + 1][c + 1];
	if(answer < sum) answer = sum;
}

void case4(int r, int c)
{
	int sum = 0;
	sum = board[r][c] + board[r - 1][c + 1] + board[r][c + 1] + board[r + 1][c + 1];
	if(answer < sum) answer = sum;
}

int main()
{
    std::cin >> N >> M;

    board.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            std::cin >> board[i][j];
        }
    }
    
     for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            DFS(i, j);
            visited[i][j] = false;
            if (i - 1 >= 0 && j + 2 < M) case1(i, j);
			if (j + 2 < M && i + 1 < N) case2(i, j);
			if (i + 2 < N && j + 1 < M) case3(i, j);
			if (i + 1 < N && i - 1 >= 0 && j + 1 < M) case4(i, j);
        }
    }

    std::cout << answer;
}