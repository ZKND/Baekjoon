#include<iostream>
#include<vector>
#include<algorithm>

class member
{
    public:

    int age;
    std::string name;
    int ID;
    member();
    void getMember(int ageInput, std::string nameInput, int idInput);
};
member::member()
{
    age = 0;
    name = "";
    ID = -1;
}
void member::getMember(int ageInput, std::string nameInput, int idInput)
{
    age = ageInput;
    name = nameInput;
    ID = idInput;
}

bool compare(member a, member b)
{
    if(a.age != b.age)
    {
        return a.age < b.age;
    }
    else return a.ID < b.ID;
}
int main()
{
    int N= 0;

    std::cin >> N;
    std::vector<member> Members(N);

    int ageTemp;
    std::string nameTemp;

    for(int i = 0; i < N; i++)
    {
        std::cin >> ageTemp >> nameTemp;
        Members[i].getMember(ageTemp, nameTemp, i);
    }

    sort(Members.begin(), Members.end(), compare);

    for(int i = 0; i < N; i++)
    {
        std::cout << Members[i].age << " " << Members[i].name;
        if(i != N - 1) std::cout << "\n";
    }
}