#include <iostream>
using namespace std;

template <typename T>

class Node
{
public:
    T data;
    Node<T> *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>

class Queue
{
    Node<T> *front, *rear;
    int current_size;

public:
    Queue()
    {
        front = rear = NULL;
        current_size = 0;
    }

    int getSize()
    {
        return current_size;
    }

    bool isEmpty()
    {
        return current_size == 0;
    }

    T peek()
    {
        if (front == NULL)
        {
            return 0;
        }
        else
        {
            return front->data;
        }
    }

    void enqueue(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (front == NULL)
        {
            front = rear = newNode;
            rear->next = front;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
        current_size++;
    }

    void dequeue()
    {
        if (current_size == 0)
        {
            return;
        }
        else
        {
            front = front->next;
            rear->next = front;
            current_size--;
        }
    }
    void display()
    {
        Node<T> *temp = front;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main()
{
    Queue<int> q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);

    cout << q1.peek() << endl;

    q1.dequeue();
    q1.dequeue();
    q1.dequeue();

    cout << q1.getSize() << endl;

    cout << q1.isEmpty() << endl;

    q1.display();

    return 0;
}