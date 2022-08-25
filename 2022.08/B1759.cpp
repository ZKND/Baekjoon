#include<iostream>
#include<vector>
#include<algorithm>

#define vector std::vector

int L, C;
vector<char> answer;
vector<char> input;

bool check()
{
    int vowel = 0, cons = 0;
    for(char C : answer)
    {
        switch(C)
        {
            case 'a' : case 'e' : case 'i' : case 'o' : case 'u' :
            vowel++;
            break;

            default :
            cons++;
            break;
        }        
    }
    if(vowel >= 1 && cons >= 2)
        return true;
    else
        return false;
}

void solve(int start, int depth)
{
    if(depth == L && check())
    {
        for(int i = 0; i < L; i++)
        {
            std::cout << answer[i];
        }
        std::cout << "\n";
        return;
    }

    for(int i = start; i < C; i++)
    {
        answer[depth] = input[i];

        solve(i+1, depth+1);

    }
}

int main()
{
    std::cin >> L >> C;

    input.assign(C, ' ');
    answer.assign(L, ' ');

    for(int i = 0; i < C; i++)
    {
        std::cin >> input[i];
    }

    std::sort(input.begin(), input.end());
    
    solve(0, 0);
    
}