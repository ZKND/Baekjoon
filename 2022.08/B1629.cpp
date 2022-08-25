#include <iostream>

long long answer(long long A, long long B, long long C)
{
    if(B == 0)
        return 1;

    long long val = answer(A, B/2, C);
    val = val * val % C;

    if(B % 2 == 0) return val;
    return val * A % C;
}
int main()
{
    long long A, B, C;

    std::cin >> A >> B >> C;

    std::cout << answer(A, B, C);
}