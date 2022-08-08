#include<iostream>
#include<queue>

std::priority_queue<int, std::vector<int>, std::less<int>> PQ;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, input;

    std::cin >> N;

    for(int i = 0; i < N; i++)
    {
        std::cin >> input;

        if(input == 0)
        {
            if(PQ.empty())
            {
                std::cout << "0\n";
            }
            else
            {

                std::cout << PQ.top() << "\n";
                PQ.pop();
            }
        }
        else
        {
            PQ.push(input);
        }      
    }
}