#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

int main()
{

    int T, N;
    std::string p, input, tmp;
    bool REVERSE = false;
    std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        std::cin >> p;
        std::cin >> N;
        std::cin >> input;
        REVERSE = false;
        bool error = false;
        std::deque<int> list;
        tmp = "";

        for (int j = 1; j < input.size(); j++)
        {
            if (input[j] == ',' || input[j] == ']' && !tmp.empty())
            {
                int tmpI = std::stoi(tmp);
                list.push_back(tmpI);
                tmp = "";
            }
            else
                tmp += input[j];
        }
        for (int j = 0; j < p.size(); j++)
        {
            if (list.size() == 0 && p[j] == 'D')
            {
                error = true;
                break;
            }
            if (p[j] == 'D')
            {
                if (REVERSE)
                    list.pop_back();
                else
                    list.pop_front();
            }
            else if (p[j] == 'R')
            {
                if (REVERSE)
                    REVERSE = false;
                else
                    REVERSE = true;
            }
        }

        if (error)
            std::cout << "error\n";
        else
        {
            std::cout << "[";
            for (int j = 0; j < list.size(); j++)
            {
                if (REVERSE)
                    std::cout << list[list.size() - 1 - j];
                else
                    std::cout << list[j];
                if (j != list.size() - 1)
                    std::cout << ",";
            }
            std::cout << "]\n";
        }
    }
}