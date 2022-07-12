#include<iostream>
#include<string>

bool palindrome(int& input)
{
    bool check = true;
    if(input > 9)
    {
        std::string tmp = std::to_string(input);
        int size = tmp.size();

        for(int i = 0; i < size/2; i++)
        {
            if(tmp[i] == tmp[size - 1 - i] && check) check = true;
            else check = false;
        }
        return check;       
    }
    else return true;    
}

int main()
{
    int input;

    while(true)
    {
        std::cin >> input;
        if(input == 0) break;
        else if(palindrome(input)) std::cout << "yes\n";
        else std::cout << "no\n";
    }
}