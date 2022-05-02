#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Queue
{
    Node *front_, *rear;
    int current_size;

public:
    Queue()
    {
        front_ = rear = NULL;
        current_size = 0;
    }

    void enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (front_ == NULL)
        {
            front_ = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        current_size++;
    }

    int dequeue()
    {
        if (current_size == 0)
        {
            return -1;
        }
        else
        {
            int temp = front_->data;
            front_ = front_->next;
            current_size--;
            return temp;
        }
    }

    int front()
    {
        if (front_ == NULL)
        {
            return -1;
        }
        else
        {
            return front_->data;
        }
    }

    int getSize()
    {
        return current_size;
    }

    bool isEmpty()
    {
        return current_size == 0;
    }
};

int main()
{
    Queue q;

    int t;
    cin >> t;

    while (t--)
    {
        int choice, input;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            q.enqueue(input);
            break;
        case 2:
            cout << q.dequeue() << "\n";
            break;
        case 3:
            cout << q.front() << "\n";
            break;
        case 4:
            cout << q.getSize() << "\n";
            break;
        default:
            cout << ((q.isEmpty()) ? "true\n" : "false\n");
            break;
        }
    }
}