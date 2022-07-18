#include<iostream>
#include<cmath>

void answer(int N, int r, int c, int& cnt)  // 0 ≤ r, c < 2N
{
    int half = (int) std::pow(2, N-1);
    int pTemp = (int) std::pow(half, 2); // 1/4칸의 갯수

    if (r >= half && c >= half)
    {
        cnt += pTemp * 3;
        if(N == 1)  return;
        answer(N - 1, r % half, c % half, cnt);
    }
    else if (r >= half)
    {
        cnt += pTemp * 2;
        if(N == 1)  return;
        answer(N - 1, r % half, c % half, cnt);
    }
    else if (c >= half)
    {
        cnt += pTemp;
        if(N == 1)  return;
        answer(N - 1, r % half, c % half, cnt);
    }
    else
    {
        if(N == 1)  return;
        answer(N - 1, r % half, c % half, cnt);
    }
}

int main()
{
    int N = 0, r = 0, c = 0, cnt = 0;

    std::cin >> N >> r >> c; // r == 행 c == 열,    0 ≤ r, c < 2^N
    answer(N, r, c, cnt);     
    std::cout << cnt;
}