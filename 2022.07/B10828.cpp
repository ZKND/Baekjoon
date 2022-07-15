#include<iostream>
#include<stack>


int main()
{   
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::stack<int> sta;
    int input = 0, N = 0;

    std::cin >> N;
    std::string cmd, tmp;

    for(int i = 0; i < N; i++)
    {
        std::cin >> cmd;
        if(cmd == "push")
        {
            std::cin >> input;
            sta.push(input);
        }
        else if(cmd == "pop")
        {
            if(sta.empty()) std::cout << "-1" << "\n";
            else
            {
                std::cout << sta.top() << "\n";
                sta.pop();
            }
        }
        else if(cmd == "size")
        {
            std::cout << sta.size() << "\n";
        }
        else if(cmd == "empty")
        {
            if(sta.empty()) std::cout << "1\n";
            else std::cout << "0\n";
        }
        else if(cmd == "top")
        {
            if(sta.empty()) std::cout << "-1\n";
            else std::cout << sta.top() << "\n";
        }
    }
}