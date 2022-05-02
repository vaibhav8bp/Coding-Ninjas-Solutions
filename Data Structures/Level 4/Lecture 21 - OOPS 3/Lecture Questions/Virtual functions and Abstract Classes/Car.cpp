class Car : public Vehicle
{
public:
	int numGears;

	void print()
	{
		cout << "Car's print" << endl;
	}
	//If we don't implement Car's print it will throw error as we have to implement all pure virtual functions of Vehcile class here
};