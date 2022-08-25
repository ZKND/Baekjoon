#include <iostream>
#include <string>

int count;

int recursion(const std::string& s, int l, int r){
    count++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const std::string& s){
    count = 0;
    return recursion(s, 0, s.length()-1);
}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::string input;

    std::cin >> T;

    for(int i = 0; i < T; i++)
    {
        std::cin >> input;

        std::cout << isPalindrome(input) << " " << count << "\n";
    }
}