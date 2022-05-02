#include <iostream>
using namespace std;

class dynamic_array
{
    int *data;
    int start_index;
    int size;

public:
    dynamic_array()
    {
        data = new int[5];
        start_index = 0;
        size = 5;
    }

    dynamic_array(dynamic_array const &d1)
    {
        // This is shallow copy
        // this->data=d1.data;

        // This is deep copy
        this->data = new int[d1.size];
        for (int i = 0; i < d1.start_index; i++)
        {
            this->data[i] = d1.data[i];
        }
        this->start_index = d1.start_index;
        this->size = d1.size;
    }

    void operator=(dynamic_array const &d1)
    {
        // This is shallo copy
        // this->data=d1.data;

        // This is deep copy
        this->data = new int[d1.size];
        for (int i = 0; i < d1.start_index; i++)
        {
            this->data[i] = d1.data[i];
        }
        this->start_index = d1.start_index;
        this->size = d1.size;
    }

    void add(int element)
    {
        if (start_index == size)
        {
            int *newdata = new int[2 * size];
            for (int i = 0; i < size; i++)
            {
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
            size *= 2;
        }
        data[start_index] = element;
        start_index++;
    }
    int get_element(int i) const
    {
        if (i < start_index)
        {
            return data[i];
        }
        else
        {
            return -1;
        }
    }
    void add_element_at_particular_index(int index, int element)
    {
        if (index < start_index)
        {
            data[index] = element;
        }
        else if (index == start_index)
        {
            add(element);
        }
        else
        {
            return;
        }
    }
    void display() const
    {
        for (int i = 0; i < start_index; i++)
        {
            cout << this->data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    dynamic_array d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    cout << "Original object d1 : - " << endl;
    d1.display();
    dynamic_array d2(d1); // copy constructor
    cout << "Original object d2 : - " << endl;
    d2.display();
    dynamic_array d3;
    d3 = d1;
    cout << "Original object d3 : - " << endl;
    d3.display();
    d2.add_element_at_particular_index(2, 90);
    d3.add_element_at_particular_index(1, 100);
    cout << "d2 after changing" << endl;
    d2.display();
    cout << "d3 after changing" << endl;
    d3.display();
    cout << "d1 after changing d2 and d3" << endl;
    d1.display();
    return 0;
}