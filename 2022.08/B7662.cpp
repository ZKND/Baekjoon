#include<iostream>
#include<map>
#include<set>

std::multiset<int> SET;
std::map<char, bool> CMDList;

int T, K, input;
char CMD;

void INPUT()
{
    SET.insert(input);
}
void DELETE()
{
    if(input == 1)
    {
        auto it = SET.end();
        it--;
        SET.erase(it);
    }
    else
        SET.erase(SET.begin());
}
int main()
{
    CMDList['I'] = true;    // 입력 - true
    CMDList['D'] = false;   // 삭제 - false

    std::cin >> T;
    for(int i = 0; i < T; i++)
    {
        SET.clear();
        std::cin >> K;
        for(int j = 0; j < K; j++)
        {
            std::cin >> CMD >> input;
            switch(CMDList[CMD])
            {
            case true:
                INPUT();
                break;
            case false:
                if (!SET.empty())
                {
                    DELETE();
                }
                break;
            }
        }

        if(SET.empty())
            std::cout << "EMPTY\n";
        else
        {
            auto it = SET.end();
            it--;
            std::cout << *it << " " << *SET.begin() << "\n";
        }
    }
}