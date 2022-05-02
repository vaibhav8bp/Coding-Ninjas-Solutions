#include <iostream>
using namespace std;

class Deque
{
    int front, rear, size;
    int data[10];

public:
    Deque(int size)
    {
        front = -1;
        rear = 0;
        this->size = size;
    }
    void insertFront(int element)
    {
        if ((rear + 1) % size == front)
        {
            cout << "-1\n";
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        data[front] = element;
    }
    void insertRear(int element)
    {
        if ((rear + 1) % size == front)
        {
            cout << "-1\n";
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        data[rear] = element;
    }
    void deleteFront()
    {
        if (front == -1)
        {
            cout << "-1\n";
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    void deleteRear()
    {
        if (front == -1)
        {
            cout << "-1\n";
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }

    int getFront()
    {
        if (front == -1)
        {
            return -1;
        }
        return data[front];
    }
    int getRear()
    {
        if (front == -1)
        {
            return -1;
        }
        return data[rear];
    }
};

int main()
{
    Deque dq(10);
    int choice, input;
    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            dq.insertFront(input);
            break;
        case 2:
            cin >> input;
            dq.insertRear(input);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5:
            cout << dq.getFront() << "\n";
            break;
        case 6:
            cout << dq.getRear() << "\n";
            break;
        default:
            return 0;
        }
    }
    return 0;
}