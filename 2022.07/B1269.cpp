#include<iostream>
#include<set>
#include<algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N = 0, M = 0, temp = -1, cnt = 0;

    std::set<int> arrA;
    std::set<int> arrB;

    std::cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        std::cin >> temp;
        arrA.insert(temp);
    }

    for(int i = 0; i < M; i++)
    {
        std::cin >> temp;
        arrB.insert(temp);
    }
    
    for(const auto& A : arrA)
    {
        if(arrB.find(A) == arrB.end()) cnt++;
    }
    for(const auto& B : arrB)
    {
        if(arrA.find(B) == arrA.end()) cnt++;
    }

    std::cout << cnt;    
}