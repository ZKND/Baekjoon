#include<iostream>
#include<vector>

#define vector std::vector

vector<vector<std::pair<int, int>>> edges;
vector<bool> visited;
vector<int> length;

int V, answer = 0;
int FAR = -1, farP;

void DFS(int start)
{
    visited[start] = true;
    for(std::pair<int, int> point : edges[start])
    {
        if(!visited[point.first])
        {

            if(length[point.first] < length[start] + point.second)
                length[point.first] = length[start] + point.second;
            if(FAR < length[point.first])
            {                
                FAR = length[point.first];
                farP = point.first;
            } 
            
            DFS(point.first);
            visited[point.first] = false;
        }
    }
    


    /*
    for(std::pair<int, int> edge : edges[start])
    {
       if (!visited[edge.first])
        {
            if (length[edge.first] <= length[start] + edge.second)
            {
                length[edge.first] = length[start] + edge.second;
            }
            if (answer <= length[edge.first])
                answer = length[edge.first];

            DFS(edge.first);
        }
    }
    */
}

int main()
{
    std::cin >> V;
    edges.assign(V + 1, vector<std::pair<int,int>>());
    // length.assign(V + 1, 0);
    visited.assign(V + 1, false);

    int input, len, point;

    for(int i = 1; i <= V; i++)
    {
        std::cin >> point;
        while(true)
        {
            std::cin >> input;
            if(input == -1)
                break;
            std::cin >> len;
            edges[point].push_back({input, len});
        }
    }   // 간선 정보 입력

    length.assign(V + 1, 0);
    DFS(1);
    answer += FAR;
    //std::cout << FAR << "\n";
    FAR = 0;
    length.assign(V + 1, 0);
    visited.assign(V + 1, false);
    DFS(farP);
    answer += FAR;
    //std::cout << FAR << "\n";
    //FAR = 0;
    /*
    for(int i = 1; i <= V; i++)
    {
        length.assign(V + 1, 0);
        DFS(i);
    }
*/    
    std::cout << FAR;

}