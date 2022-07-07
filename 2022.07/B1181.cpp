#include<iostream>
#include<algorithm>
#include<vector>

bool compare(std::string a, std::string b)
{
    if(a.size() == b.size())
    {
        return a < b;
    }
    else return a.size() < b.size();
}

int main()
{
    int N = 0;

    std::cin >> N;

    std::vector<std::string> words(N, "");
    
    for(int i = 0; i < N; i++)
    {
        std::cin >> words[i];
    }

    sort(words.begin(), words.end(), compare);
    words.erase(std::unique(words.begin(), words.end()), words.end());

    for(int i = 0; i < N; i++)
    {
        std::cout << words[i];
        if(i != N - 1) std::cout << "\n";
    }
}