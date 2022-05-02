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

	// Vehicle()
	// {
	// 	cout << "Vehicle's default constructor " << endl;
	// }

	Vehicle(int z)
	{
		cout << "Vehicle's Parametrized constructor " << endl;
		maxSpeed = z;
	}

	~Vehicle()
	{
		cout << "Vehicle's Destructor " << endl;
	}
};

class Car : public Vehicle
{
public:
	int numGears;

	Car(int x, int y) : Vehicle(x)
	{
		cout << "Car's constructor " << endl;
		numGears = y;
	}

	~Car()
	{
		cout << "Car's Destructor " << endl;
	}

	void print()
	{
		cout << "NumTyres : " << numTyres << endl;
		cout << "Color : " << color << endl;
		cout << "Num gears : " << numGears << endl;
		// cout << "Max Speed : " << maxSpeed << endl;
	}
};

class HondaCity : public Car
{
public:
	HondaCity(int x, int y) : Car(x, y)
	{
		cout << "Honda city constructor " << endl;
	}

	~HondaCity()
	{
		cout << "Honda city destructor " << endl;
	}
};

int main()
{
	HondaCity h(4, 5);

	// Vehicle v(4);

	// v.color = "Blue"; // This is correct
	// v.maxSpeed = 100; // This is wrong
	// v.numTyres = 4; // This is wrong

	// Car c(5, 10);

	// c.color = "Black"; // This is correct
	// c.numTyres = 4; // This is wrong
	// c.numGears = 5; // This is correct
}