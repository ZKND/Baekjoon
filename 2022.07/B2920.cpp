#include<iostream>

int main()
{

    bool asc = true, desc = true, mix = false;

    int arr[8];
    
    for(int i = 0; i < 8; i++)
    {
        std::cin >> arr[i];
        if(i > 0)
        {
            if(arr[i] == arr[i-1]-1 && desc)
            {
                desc = true;
                asc = false;
            }
            else if(arr[i] == arr[i-1]+1 && asc)
            {
                asc = true;
                desc = false;
            }
            else
            {
                asc = false;
                desc = false;
                mix = true;
            }
        }
    }

    if(asc) std::cout << "ascending";
    else if(desc) std::cout << "descending";
    else if(mix) std::cout << "mixed";

}