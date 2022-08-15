#include<iostream>
#include<map>

int main()
{
    std::map<std::string, float> GRADE;
    GRADE["A+"] = 4.3;
    GRADE["A0"] = 4.0;
    GRADE["A-"] = 3.7;
    GRADE["B+"] = 3.3;
    GRADE["B0"] = 3.0;
    GRADE["B-"] = 2.7;
    GRADE["C+"] = 2.3;
    GRADE["C0"] = 2.0;
    GRADE["C-"] = 1.7;
    GRADE["D+"] = 1.3;
    GRADE["D0"] = 1.0;
    GRADE["D-"] = 0.7;
    GRADE["F"] = 0.0;

    std::string input;
    std::cin >> input;

    std::cout << std::fixed;
    std::cout.precision(1);
    std::cout << GRADE[input];    
}