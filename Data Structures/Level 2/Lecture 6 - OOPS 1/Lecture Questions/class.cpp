#include <iostream>
using namespace std;

class student
{
    int age;

public:
    student()
    {
        cout << "Constructor called" << endl;
    }
    ~student()
    {
        cout << "Destructor called!" << endl;
    }
    int rollNumber;
    void display()
    {
        cout << age << " " << rollNumber << endl;
    }
    void setAge(int a)
    {
        age = a;
    }
    int getAge()
    {
        return age;
    }
};

int main()
{
    student *s1 = new student;
    delete s1;
    student *s2 = new student;
    delete s2;
    student s3;
    s1->setAge(20);
    s1->rollNumber = 101;
    s1->display();
    return 0;
}