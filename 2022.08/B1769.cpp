#include<iostream>
#include<string>

std::string input;

int cnt = 0;

std::string convert(std::string n)
{
    if((n.length()) == 1)
        return n;
    cnt++;
    int sum = 0;
    for(char c : n)
    {
        sum += c-'0';
    }
    return convert(std::to_string(sum));

}



int main()
{
    std::cin >> input;

    int answer = std::stoi(convert(input));

    std::cout << cnt << "\n";

    if(answer % 3 == 0)
        std::cout << "YES";
    else
        std::cout << "NO";
}