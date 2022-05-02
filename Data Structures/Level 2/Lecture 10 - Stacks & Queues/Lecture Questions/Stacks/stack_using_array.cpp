#include <iostream>
using namespace std;

#include <climits>
class StackUsingArray
{
    // Privately declared
    int *data;     // Dynamic array created serving as stack
    int nextIndex; // To keep the track of current top index
    int capacity;  // To keep the track of total size of stack
public:
    StackUsingArray(int totalSize)
    { // Constructor to initialise the values
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
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
            cout << "Stack full " << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++; // Size incremented
    }
    // delete element
    int pop()
    {
        // Before deletion we checked if it was initially not empty to prevent underflow
        if (isEmpty())
        {
            cout << "Stack is empty " << endl;
            return INT_MIN;
        }
        nextIndex--; // Conditioned satisfied so deleted
        return data[nextIndex];
    }
    // to return the top element of the stack
    int top()
    {
        if (isEmpty())
        { // checked for empty stack to prevent overflow
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