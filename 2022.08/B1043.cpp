#include<iostream>
#include<vector>
#include<queue>

#define vector std::vector

vector<bool> Knows; // 진실 여부
vector<vector<int>> meet;
vector<int> members;    // 파티에 참가한 사람

vector<vector<int>> parties;

vector<bool> party;
std::queue<int> Q;

int N, M, knowNum, answer = 0;

int main()
{
    std::cin >> N >> M;
    Knows.assign(N, false);
    meet.assign(N,vector<int>());

    parties.assign(M, vector<int>());
    party.assign(M, false);

    vector<int> knowpeople;


    std::cin >> knowNum;
    for(int i = 0; i < knowNum; i++)
    {
        int who;
        std::cin >> who;
        Knows[who - 1] = true;
        knowpeople.push_back(who);
    }

    for (int i = 0; i < M; i++)
    {
        int people;
        std::cin >> people;
        bool know = false;
        for (int j = 0; j < people; j++)
        {
            int who;
            std::cin >> who;
            parties[i].push_back(who);
            if (Knows[who - 1])
                know = true;
        }
        if(know)
            party[i] = true;
    }

    for(vector<int> list : parties)
    {
        for(int who : list)
        {
            for(int i = 0; i < list.size(); i++)
            {
                if (who != list[i])
                    meet[who - 1].push_back(list[i]);
            }
        }
    }
    
    for(int who : knowpeople)   {Q.push(who);}

    while(!Q.empty())
    {
        int tmp = Q.front();
        Q.pop();
        
        for(int i = 0; i < meet[tmp - 1].size(); i++)
        {
            if(!Knows[meet[tmp-1][i]-1])
            {
                Knows[meet[tmp-1][i]-1] = true;
                Q.push(meet[tmp-1][i]);
            }
        }
    }

    /*
    for(int i = 0; i < M; i++)
    {
        if(party[i])
        {
            for(int person : parties[i])
            {
                Knows[person - 1] = true;
            }
        }
    }*/   // Knows 벡터 값 확인하는 용도

    for(vector<int> list : parties)
    {
        bool check = false;
        for(int person : list)
        {
            if(Knows[person - 1])
            {
                check = true;
                break;                
            }
        }
        if(!check)
        {
            answer++;
        }
    }

    std::cout << answer;

}