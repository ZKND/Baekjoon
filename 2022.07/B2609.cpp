#include<iostream>

int main()
{
    int min, max, tmp;

    std::cin >> min >> max;

    if(min == max)
    {
        std::cout << min << "\n" << min;
        return 0;
    }
    else if(min > max)
    {
        tmp = min;
        min = max;
        max = tmp;
    }

    tmp = min;
    for(;tmp >= 1; tmp--)
    {
        if(min % tmp == 0 && max % tmp == 0)
        {
            std::cout << tmp << "\n";
            break;
        }
    }
    tmp = 1;
    while(true)
    {
        if((min * tmp)%max == 0)
        {
            std::cout << min*tmp;
            break;
        }
        tmp++;        
    }
}