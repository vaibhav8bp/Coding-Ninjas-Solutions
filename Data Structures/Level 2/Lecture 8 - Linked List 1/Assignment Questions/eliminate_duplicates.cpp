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

Node *removeDuplicates(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *previous = head;
    Node *current = head->next;
    while (current != NULL)
    {
        if (previous->data == current->data)
        {
            previous->next = current->next;
            current = current->next;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
    return head;
}

// or

/*
Node *removeDuplicates(Node *head)
{
    if(head==NULL)
    {
        return head;
    }
    Node *current = head;
    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            current->next = current->next->next;
        }
        else
        {
            current = current->next;
        }
    }
    return head;
}
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        head = removeDuplicates(head);
        print(head);
    }
    return 0;
}