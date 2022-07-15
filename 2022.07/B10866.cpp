#include<iostream>
#include<deque>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::deque<int> DQ;
    std::string cmd;

    int N = 0, input = -1;

    std::cin >> N;
    for(int i = 0; i < N; i++)
    {
        std::cin >> cmd;

        if(cmd == "push_front")
        {
            std::cin >> input;
            DQ.push_front(input);
        }
        else if(cmd == "push_back")
        {
            std::cin >> input;
            DQ.push_back(input);
        }
        else if(cmd == "pop_front")
        {
            if(DQ.empty()) std::cout << "-1\n";
            else
            {
                std::cout << DQ.front() << "\n";
                DQ.pop_front();
            }
        }
        else if(cmd == "pop_back")
        {
            if(DQ.empty()) std::cout << "-1\n";
            else
            {
                std::cout << DQ.back() << "\n";
                DQ.pop_back();
            }
        }
        else if(cmd == "size")
        {
            std::cout << DQ.size() << "\n";
        }
        else if(cmd == "empty")
        {
            if(DQ.empty()) std::cout << "1\n";
            else std::cout << "0\n";
        }
        else if(cmd == "front")
        {
            if(DQ.empty()) std::cout << "-1\n";
            else std::cout << DQ.front() << "\n";
        }
        else if(cmd == "back")
        {
            if(DQ.empty()) std::cout << "-1\n";
            else std::cout << DQ.back() << "\n";
        }
    }
}