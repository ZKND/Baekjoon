#include<iostream>
#include<vector>

int main()
{
    std::vector<bool> report(31, false);
    
    for(int i = 0; i < 28; i++)
    {
        int tmp;
        std::cin >> tmp;
        report[tmp] = true;
    }

    for(int i = 1; i <= 30; i++)
    {
        if(!report[i])
            std::cout << i << "\n";
    }
    
}