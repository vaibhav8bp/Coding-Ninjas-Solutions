#include <iostream>
using namespace std;

int total_salary(int basic, char grade)
{
    float hra, da, pf, total;
    int allow, round_total;
    hra = (.2) * basic;
    da = (.5) * basic;
    pf = (.11) * basic;
    if (grade == 65)
    {
        allow = 1700;
    }
    else if (grade == 66)
    {
        allow = 1500;
    }
    else
    {
        allow = 1300;
    }
    total = basic + hra + da + allow - pf;
    round_total = total;
    if (total - round_total < .5)
    {
        cout << round_total;
    }
    else
    {
        cout << round_total + 1;
    }
}

int main()
{
    int basic;
    char grade;
    cin >> basic >> grade;
    total_salary(basic, grade);
    return 0;
}