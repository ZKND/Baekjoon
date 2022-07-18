#include<iostream>
#include<vector>
#include<string>

std::vector<bool> button(10,true);
bool check(const std::string& str)
{
    bool chk = true;
    for (auto cha : str)
    {
        if (!button[cha - '0'])
        {
            chk = false;
            break;
        }
    }
    return chk;
}

int main()
{
    int target = 0, M = 0, answer;  // 0 <= N <= 500000, 0 <= M <= 10
    std::cin >> target >> M;
    
    if(target == 100)
    {
        std::cout << 0;
        return 0;
    }

    std::string strTarget = std::to_string(target);
    int sub = std::abs(target - 100);

    for(int i = 0; i < M; i++)   // 망가진 버튼
    {
        int tmp;
        std::cin >> tmp;
        button[tmp] = false;
    }
//-------------채널에 해당되는 버튼이 모두 멀쩡한 경우-------------------------------
    bool chk = check(strTarget);
    if (chk)
    {
        answer = strTarget.size();
        answer < sub ? std::cout << answer : std::cout << sub;
        return 0;
    }
//-------------채널에 해당되는 버튼이 모두 멀쩡한 경우-------------------------------


    int limit = 1000000, min = 500000;
    
    for(int i = 0; i < 1000000; i++)
    {
        std::string tmp = std::to_string(i);
        if(check(tmp))
        {
            int tmpN = (int)abs(target - i) + tmp.size();
            if(tmpN < min) min = tmpN;
        }
    }

    if(sub < min) min = sub;

    std::cout << min;
}
