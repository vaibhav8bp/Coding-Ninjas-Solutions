#include <iostream>
using namespace std;

#include <climits>
class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        data = new int[4]; // initially declared with a small size of 4
        nextIndex = 0;
        capacity = 4;
    }
    // return the number of elements present in my stack
    int size()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        return nextIndex == 0;
    }
    // insert element
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            int *newData = new int[2 * capacity]; // Capacity doubled
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i]; // Elements copied
            }
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    // delete element
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty " << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty " << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};

int main()
{
    return 0;
}