#include <iostream>
using namespace std;

class Polynomial
{
public:
    int *degCoeff;
    int capacity;
    //Default Constructor
    Polynomial()
    {
        degCoeff = new int[10];
        for (int i = 0; i < 10; i++)
        {
            degCoeff[i] = 0;
        }
        capacity = 10;
    }
    //Copy Constructor
    Polynomial(Polynomial const &p)
    {
        //shallow copy;
        this->degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }

    void operator=(Polynomial const &p)
    {
        //shallow copy;
        this->degCoeff = new int[p.capacity];
        for (int i = 0; i < p.capacity; i++)
        {
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }

    void setCoefficient(int index, int coeff)
    {
        if (index >= capacity)
        {
            int size = index + 1;
            int *p1 = new int[size];
            for (int i = 0; i < capacity; i++)
            {
                p1[i] = degCoeff[i];
            }
            for (int i = capacity; i < size; i++)
            {
                p1[i] = 0;
            }
            delete[] degCoeff;
            degCoeff = p1;
            capacity = size;
        }
        degCoeff[index] = coeff;
    }
    Polynomial operator+(Polynomial const &p)
    {
        int max = (capacity > p.capacity) ? (capacity) : (p.capacity);
        Polynomial pNew;
        pNew.capacity = max;
        pNew.degCoeff = new int[pNew.capacity];
        int i = 0, j = 0, k = 0;
        while (i < capacity && j < p.capacity)
        {
            pNew.degCoeff[k++] = degCoeff[i++] + p.degCoeff[j++];
        }
        while (i < capacity)
        {
            pNew.degCoeff[k++] = degCoeff[i++];
        }
        while (j < p.capacity)
        {
            pNew.degCoeff[k++] = p.degCoeff[j++];
        }

        return pNew;
    }

    Polynomial operator-(Polynomial const &p)
    {
        int max = (capacity > p.capacity) ? (capacity) : (p.capacity);
        Polynomial pNew;
        pNew.capacity = max;
        pNew.degCoeff = new int[pNew.capacity];
        int i = 0, j = 0, k = 0;
        while (i < capacity && j < p.capacity)
        {
            pNew.degCoeff[k++] = degCoeff[i++] - p.degCoeff[j++];
        }
        while (i < capacity)
        {
            pNew.degCoeff[k++] = degCoeff[i++];
        }
        while (j < p.capacity)
        {
            pNew.degCoeff[k++] = -p.degCoeff[j++];
        }

        return pNew;
    }

    Polynomial operator*(Polynomial const &p)
    {
        Polynomial pNew;
        pNew.capacity = capacity + p.capacity;
        pNew.degCoeff = new int[pNew.capacity];

        for (int i = 0; i < pNew.capacity; i++)
        {
            pNew.degCoeff[i] = 0;
        }
        for (int i = 0; i < capacity; i++)
        {
            for (int j = 0; j < p.capacity; j++)
            {
                pNew.degCoeff[i + j] = pNew.degCoeff[i + j] + (degCoeff[i] * p.degCoeff[j]);
            }
        }
        return pNew;
    }

    void print()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (degCoeff[i])
            {
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    int count1, count2, choice;
    cin >> count1;
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    for (int i = 0; i < count1; i++)
    {
        cin >> degree1[i];
    }
    for (int i = 0; i < count1; i++)
    {
        cin >> coeff1[i];
    }
    Polynomial first;
    for (int i = 0; i < count1; i++)
    {
        first.setCoefficient(degree1[i], coeff1[i]);
    }
    cin >> count2;
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    for (int i = 0; i < count2; i++)
    {
        cin >> degree2[i];
    }
    for (int i = 0; i < count2; i++)
    {
        cin >> coeff2[i];
    }
    Polynomial second;
    for (int i = 0; i < count2; i++)
    {
        second.setCoefficient(degree2[i], coeff2[i]);
    }
    cin >> choice;

    switch (choice)
    {
        // Add
    case 1:
    {
        Polynomial result1 = first + second;
        result1.print();
        break;
    }
        // Subtract
    case 2:
    {
        Polynomial result2 = first - second;
        result2.print();
        break;
    }
        // Multiply
    case 3:
    {
        Polynomial result3 = first * second;
        result3.print();
        break;
    }
    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }
    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }
    }
    return 0;
}