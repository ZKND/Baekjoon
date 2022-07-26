#include <iostream>
#include <string>

int main()
{
    std::string input, tmp = "";
    int answer = 0;
    bool chk = false;
    std::cin >> input;

    for (int i = 0; i <= input.size(); i++)
    {
        if (input[i] == '+' || input[i] == '-' || i == input.size())
        {
            if (chk)
                answer -= std::stoi(tmp);
            else
                answer += std::stoi(tmp);
            tmp = "";
            if (input[i] == '-')
            {
                chk = true;
            }
        }
        else
        {
            tmp += input[i];
        }
    }
    std::cout << answer;
}