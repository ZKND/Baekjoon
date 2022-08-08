#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#define vector std::vector

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::map<std::string, int> CMDList;
    CMDList["add"] = 0;
    CMDList["remove"] = 1;
    CMDList["check"] = 2;
    CMDList["toggle"] = 3;
    CMDList["all"] = 4;
    CMDList["empty"] = 5;

    vector<bool> List(21, false);
    int M;
    std::string CMD;
    int input;

    std::cin >> M;

    for (int i = 0; i < M; i++)
    {
        std::cin >> CMD;
        switch (CMDList[CMD])
        {
        case 0:
            std::cin >> input;
            if (!List[input])
                List[input] = true;
            break;
        case 1:
            std::cin >> input;
            if (List[input])
                List[input] = false;
            break;
        case 2:
            std::cin >> input;
            if (List[input])
                std::cout << "1\n";
            else
                std::cout << "0\n";
            break;
        case 3:
            std::cin >> input;
            List[input] = !List[input];
            break;
        case 4:
            List.assign(21, true);
            break;
        case 5:
            List.assign(21, false);
            break;
        }
    }
}