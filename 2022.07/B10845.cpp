#include<iostream>
#include<queue>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N = 0, tmp = 0, input = -1;
    std::string cmd;
    std::queue<int> Q;

    std::cin >> N;

    for(int i = 0; i < N; i++)
    {
        std::cin >> cmd;
        if(cmd == "push")
        {
            std::cin >> input;
            Q.push(input);            
        }
        else if(cmd == "pop")
        {
            if(Q.empty()) std::cout << "-1\n";
            else
            {
                std::cout << Q.front() << "\n";
                Q.pop();
            }
        }
        else if(cmd == "size")
        {
            std::cout << Q.size() << "\n";
        }
        else if(cmd == "empty")
        {
            if(Q.empty()) std::cout << "1\n";
            else std::cout << "0\n";
        }
        else if(cmd == "front")
        {
            if(!Q.empty()) std::cout << Q.front() << "\n";
            else std::cout << "-1\n";
        }
        else if(cmd == "back")
        {
            if(!Q.empty()) std::cout << Q.back() << "\n";
            else std::cout << "-1\n";
        }
    }
}