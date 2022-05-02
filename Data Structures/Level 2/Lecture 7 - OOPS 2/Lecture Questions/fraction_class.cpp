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
        cout << this->numerator << " / " << this->denominator;
    }

    void simplify()
    {
        int min = (numerator <= denominator) ? (numerator) : (denominator);
        int gcd = 1;
        for (int i = 1; i <= min; i++)
        {
            if ((numerator % i == 0) && (denominator % i == 0))
            {
                gcd = i;
            }
        }
        this->numerator /= gcd;
        this->denominator /= gcd;
    }

    fraction operator+(fraction const &f2) const
    {
        // can use this also here with numerator and denominator
        int d = denominator * f2.denominator;
        int n = (numerator * f2.denominator) + (f2.numerator * denominator);
        fraction f3(n, d);
        f3.simplify();
        return f3;
    }

    fraction operator*(fraction const &f2) const
    {
        int n = numerator * f2.numerator;
        int d = denominator * f2.denominator;
        fraction f3(n, d);
        f3.simplify();
        return f3;
    }

    fraction &operator++()
    {
        this->numerator += this->denominator;
        simplify();
        return *this;
    }

    fraction operator++(int)
    {
        fraction fNew(numerator, denominator);
        fNew.simplify();
        numerator += denominator;
        simplify();
        return fNew;
    }

    fraction &operator+=(fraction const &f2)
    {
        numerator = numerator * f2.denominator + denominator * f2.numerator;
        denominator *= f2.denominator;
        simplify();
        return *this;
    }
    
    bool operator==(fraction const &f2) const
    {
        if (numerator == f2.numerator && denominator == f2.denominator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    fraction f1(10, 2);
    fraction f2(15, 4);
    /*
    f1.display();
    cout << " + ";
    f2.display();
    cout << " = ";
    fraction f3 = f1 + f2;
    f3.display();
    cout << endl;
    f1.display();
    cout << " * ";
    f2.display();
    cout << " = ";
    f3 = f1 * f2;
    f3.display();
    cout << endl;
    if (f1 == f2)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not Equal" << endl;
    }
    */

    /*
    ++(++f1);
    f1.display();
    */
    /*
    fraction f3 = f1++;
    f1.display();
    cout << endl;
    f3.display();
    */
    (f1 += f2) += f2;
    f1.display();
    cout << endl;
    f2.display();
    cout << endl;
    return 0;
}