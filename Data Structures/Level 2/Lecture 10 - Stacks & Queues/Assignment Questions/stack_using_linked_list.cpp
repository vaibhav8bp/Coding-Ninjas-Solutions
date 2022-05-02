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

class Stack
{
    Node *head;
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
    int top()
    {
        if (head == NULL)
        {
            return -1;
        }
        return head->data;
    }
    void push(int element)
    {
        Node *newNode = new Node(element);
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
    int pop()
    {
        if (head == NULL)
        {
            return -1;
        }
        int popped_element = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        capacity--;
        return popped_element;
    }
    void display()
    {
        Node *temp = head;
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
    Stack st;

    int q;
    cin >> q;

    while (q--)
    {
        int choice, input;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            st.push(input);
            break;
        case 2:
            cout << st.pop() << "\n";
            break;
        case 3:
            cout << st.top() << "\n";
            break;
        case 4:
            cout << st.getSize() << "\n";
            break;
        default:
            cout << ((st.isEmpty()) ? "true\n" : "false\n");
            break;
        }
    }
}