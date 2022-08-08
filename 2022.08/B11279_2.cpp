#include<iostream>
#include<vector>

#define NEXT1 tmpIdx * 2
#define NEXT2 (tmpIdx * 2) + 1
#define PARENT tmpIdx / 2

std::vector<int> HEAP(1);
int N, input;

void pop()
{
    std::cout << HEAP[1] << "\n";
    int tmp = HEAP[1];
    HEAP[1] = HEAP.back();
    HEAP.back() = tmp;
    HEAP.pop_back();

    int tmpIdx = 1;
    while (true)
    {
        if (HEAP.size() <= NEXT1)
            return;
        else if (HEAP[tmpIdx] < HEAP[NEXT1])
        {
            tmp = HEAP[tmpIdx];
            HEAP[tmpIdx] = HEAP[NEXT1];
            HEAP[NEXT1] = tmp;

            tmpIdx = NEXT1;
        }
        else if (HEAP.size() > NEXT2)
        {
            if (HEAP[tmpIdx] < HEAP[NEXT2])
            {

                tmp = HEAP[tmpIdx];
                HEAP[tmpIdx] = HEAP[NEXT2];
                HEAP[NEXT2] = tmp;

                tmpIdx = NEXT2;
            }
        }
        else
            break;
    }
}

void push(int input)
{
    HEAP.push_back(input);
    int tmpIdx = HEAP.size() - 1, tmp;

    while(true)
    {
        if(tmpIdx == 1)
            return;
        else if (HEAP[tmpIdx] > HEAP[PARENT])
        {
            tmp = HEAP[PARENT];
            HEAP[PARENT] = HEAP[tmpIdx];
            HEAP[tmpIdx] = tmp;

            tmpIdx = PARENT;      
        }
        else
            break;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;

    for(int i = 0; i < N; i++)
    {
        std::cin >> input;
        if(input == 0)
        {
            if (HEAP.size() < 2)
                std::cout << "0\n";

            else if (HEAP.size() == 2)
            {
                std::cout << HEAP[1] << "\n";
                HEAP.pop_back();
            }

            else
                pop();
        }
        else
            push(input);
    }  
}