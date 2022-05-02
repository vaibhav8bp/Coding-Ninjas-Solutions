#include <iostream>
using namespace std;

class Vehicle
{
private:
    int maxSpeed;

protected:
    int numTyres;

public:
    string color;

    Vehicle(int z)
    {
        cout << "Vehicle's default constructor called" << endl;
    }
    ~Vehicle()
    {
        cout << "Vehicle's Destructor" << endl;
    }
};

class Car : public Vehicle
{
public:
    int numGears;
    Car() : Vehicle(5)
    {
        cout << "Car's default constructor called" << endl;
    }
    ~Car()
    {
        cout << "Car's Destructor" << endl;
    }
    void print()
    {
        cout << "NumTyres : " << numTyres << endl;
        cout << "Color : " << color << endl;
        cout << " Num Gears : " << numGears << endl;
    }
};

int main()
{
    Vehicle v(5);
    v.color = "Blue";
    /*
    Cannot do this
    v.maxSpeed = 100;
    v.numTyres = 4;
    */
    Car a;
    a.color = "black";
    a.numGears = 6;
    /*
    Cannot do this
    a.numTyres = 10;
    */
    return 0;
}