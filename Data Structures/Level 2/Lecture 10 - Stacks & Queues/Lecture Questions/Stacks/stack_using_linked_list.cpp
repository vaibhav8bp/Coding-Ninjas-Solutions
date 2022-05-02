#include <iostream>
using namespace std;

template <typename A>

class Node
{
public:
    A data;
    Node<A> *next;
    Node(A data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename A>

class Stack
{
    Node<A> *head;
    int capacity;

public:
    Stack()
    {
        this->head = NULL;
        this->capacity = 0;
    }
    int getSize()
    {
        return capacity;
    }
    bool isEmpty()
    {
        return capacity == 0;
    }
    A top()
    {
        if (head == NULL)
        {
            return -1;
        }
        return head->data;
    }
    void push(A element)
    {
        Node<A> *newNode = new Node<A>(element);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        capacity++;
    }
    A pop()
    {
        if (head == NULL)
        {
            return -1;
        }
        A popped_element = head->data;
        Node<A> *temp = head;
        head = head->next;
        delete temp;
        capacity--;
        return popped_element;
    }
    void display()
    {
        Node<A> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack<char> s;

    s.push(97);  // a
    s.push(98);  // b
    s.push(99);  // c
    s.push(100); // d
    s.push(101); // e
    s.push(102); // f
    s.push(103); // g

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.getSize() << endl;

    cout << s.isEmpty() << endl;

    s.display();

    return 0;
}