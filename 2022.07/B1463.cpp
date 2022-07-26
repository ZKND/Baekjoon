#include <iostream>
#include <vector>

int main()
{
    std::vector<int> mem(1000000);
    int N, answer = 0, min;
    std::cin >> N;
    mem[1] = 0;
    mem[2] = 1;
    mem[3] = 1;
    for (int i = 4; i <= N; i++)
    {
        if (i % 3 == 0 && i % 2 == 0)
        {
            min = mem[i / 3];
            if (mem[i / 2] < min)
                min = mem[i / 2];
            if (mem[i - 1] < min)
                min = mem[i - 1];
        }
        else if (i % 3 == 0)
        {
            min = mem[i / 3];
            if (mem[i - 1] < min)
                min = mem[i - 1];
        }
        else if (i % 2 == 0)
        {
            min = mem[i / 2];
            if (mem[i - 1] < min)
                min = mem[i - 1];
        }
        else
            min = mem[i - 1];
        mem[i] = min + 1;
    }
    std::cout << mem[N];
}