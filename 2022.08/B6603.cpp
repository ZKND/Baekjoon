#include<iostream>
#include<vector>

std::vector<int> numbers;
std::vector<int> ans(6);
int K;


void answer(int idx1, int idx2)
{
    // base condition : 6개를 골랐을때 (idx2 == 6)  return
    //  


    if(idx2 == 6)
    {
        for(int i = 0; i < idx2; i++)
        {
            std::cout << ans[i] << ' ';
        }
        std::cout << "\n";
        return;
    }

    for(int i = idx1; i < K; i++)
    {
        ans[idx2] = numbers[i];
        answer(i+1, idx2+1);
    }
}
int main()
{
    
    while(std::cin >> K && K)
    {
        numbers.clear();
        for(int i = 0; i < K; i++)
        {
            int tmp;
            std::cin >> tmp;
            numbers.push_back(tmp);            
        }

        answer(0,0);
        std::cout << "\n";
    }


}