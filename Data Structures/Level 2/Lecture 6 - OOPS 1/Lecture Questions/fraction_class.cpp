#include <iostream>
using namespace std;

class fraction
{
private:
    int numerator;
    int denominator;

public:
    fraction(int numerator, int denominator)
    {
        // this keyword should be use. it is compulsory
        this->numerator = numerator;
        this->denominator = denominator;
        
    }

    void display()
    {
        // will work fine without this keyword here
        cout << this->numerator << " / " << this->denominator << endl;
    }

    int simplify(int numerator, int denominator)
    {
        if (denominator == 0)
        {
            return numerator;
        }
        int min = (numerator <= denominator) ? (numerator) : (denominator);
        int max = (numerator > denominator) ? (numerator) : (denominator);
        int mod = max % min;
        return simplify(min, mod);
    }

    void add(fraction const &f2)
    {
        // can use this also here with numerator and denominator
        int lcm = denominator * f2.denominator;
        numerator = (numerator * f2.denominator) + (f2.numerator * denominator);
        denominator = lcm;
        int gcd = simplify(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }
    void multiply(fraction const &f2)
    {
        numerator *= f2.numerator;
        denominator *= f2.denominator;
        int gcd = simplify(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }
};

int main()
{
    fraction f1(10, 2);
    f1.display();
    cout << " + ";
    fraction f2(15, 4);
    f2.display();
    cout << " = ";
    fraction f3(f1);
    f3.display();
    f1.display();
    f1.add(f2);
    f1.display();
    cout << endl;
    f3.display();
    // cout << " * ";
    // f2.display();
    // cout << " = ";
    // f3.multiply(f2);
    // f3.display();
    // cout << endl;
    return 0;
}