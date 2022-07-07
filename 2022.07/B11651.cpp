#include<iostream>
#include<vector>
#include<algorithm>

bool compare(const std::vector<int> a, const std::vector<int> b)
{
    if(a[1] == b[1])
    {
        return a[0] < b[0];
    }
    else return a[1] < b[1];
}

int main()
{
    int N = 0;
    std::cin >> N;

    std::vector<std::vector<int>> vector(N,std::vector<int>(2,0));

    for(int i = 0; i < N; i++)
    {
        std::cin >> vector[i][0] >> vector[i][1];
    }

    sort(vector.begin(),vector.end(), compare);

    for(int i = 0; i < N; i++)
    {
        std::cout << vector[i][0] << " " << vector[i][1] << "\n";
    }
}