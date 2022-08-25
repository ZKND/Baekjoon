#include <iostream>

void solve(int a, int b, int n)
{
    if(n == 1)
    {
        std::cout << a << ' ' << b << "\n";
        return;
    }

    solve(a, 6-a-b, n-1);
    std::cout << a << ' ' << b << "\n";
    solve(6-a-b, b, n-1);
}

int main()
{
    int N;
    std::cin >> N;

    std::cout << (1<<N) - 1 << "\n";

    solve(1, 3, N);

}
