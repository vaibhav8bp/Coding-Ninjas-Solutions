class Truck : virtual public Vehicle
{
public:
	Truck() : Vehicle(4)
	{
		cout << "Truck's constructor " << endl;
	}
	~Truck()
	{
		cout << "Truck's destructor" << endl;
	}
	void print()
	{
		cout << "Truck's print" << endl;
	}
};