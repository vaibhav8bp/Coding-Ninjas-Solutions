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
        this->next = NULL;
    }
};

Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *bubbleSort(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    while (true)
    {
        bool flag = true;
        Node *previous = NULL;
        Node *current = head;
        while (current->next != NULL)
        {
            Node *forward = current->next;
            if (current->data > current->next->data)
            {
                flag = false;
                if (previous == NULL)
                {
                    Node *temp = forward->next;
                    head = forward;
                    forward->next = current;
                    current->next = temp;
                    previous = head;
                }
                else
                {
                    previous->next = forward;
                    current->next = forward->next;
                    forward->next = current;
                    previous = previous->next;
                }
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
        if (flag)
        {
            break;
        }
    }
    return head;
}

int main()
{
    Node *head = takeinput();
    head = bubbleSort(head);
    print(head);
}