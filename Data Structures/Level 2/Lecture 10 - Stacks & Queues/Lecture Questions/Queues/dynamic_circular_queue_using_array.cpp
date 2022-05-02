#include <iostream>
using namespace std;

template <typename T>

class CircularQueueUsingArray
{
    int front, rear, capacity, current_size;
    T *data;

public:
    CircularQueueUsingArray()
    {
        front = rear = -1;
        capacity = 5;
        data = new T[5];
        current_size = 0;
    }
    void display()
    {
        if (front == -1 && rear == -1)
        {
            return;
        }
        int i = front;
        while (i != rear)
        {
            cout << data[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << data[i] << endl;
    }
    void enqueue(T element)
    {
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            data[rear] = element;
        }
        else if ((rear + 1) % capacity == front)
        {
            T *newData = new T[2 * capacity];
            int j = 0, i = front;
            while (i != rear)
            {
                newData[j++] = data[i];
                i = (i + 1) % capacity;
            }
            newData[j++] = data[i];
            delete[] data;
            data = newData;
            capacity *= 2;
            front = 0;
            rear = j;
            data[rear] = element;
        }
        else
        {
            rear = (rear + 1) % capacity;
            data[rear] = element;
        }
        current_size++;
    }
    void dequeue()
    {
        if (front == -1 && rear == -1)
        {
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        current_size--;
    }
    T peek()
    {
        if (front == -1 && rear == -1)
        {
            return 0;
        }
        return data[front];
    }
    bool isEmpty()
    {
        return current_size == 0;
    }
    int getSize()
    {
        return current_size;
    }
};

int main()
{
    CircularQueueUsingArray<int> c1;
    c1.enqueue(10);
    c1.enqueue(20);
    c1.enqueue(30);
    c1.enqueue(40);
    c1.enqueue(50);
    c1.enqueue(60);

    cout << c1.peek() << endl;

    c1.dequeue();
    c1.dequeue();
    c1.dequeue();

    cout << c1.getSize() << endl;

    cout << c1.isEmpty() << endl;

    c1.display();

    return 0;
}