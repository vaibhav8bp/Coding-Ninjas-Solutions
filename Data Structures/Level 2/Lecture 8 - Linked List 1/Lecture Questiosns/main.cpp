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

Node *reverseLinkedList(Node *head)
{
    Node *temp = head;
    Node *current = head;
    Node *previous = NULL;

    while (current != NULL)
    {
        temp = temp->next;
        current->next = previous;
        previous = current;
        current = temp;
    }

    return previous;
}

Node *takeInput()
{
    //-1 is the terminator
    int data;
    Node *head = NULL;
    Node *tail = NULL;
    cin >> data;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    head = reverseLinkedList(head);
    print(head);
    return 0;
}

// 1 10 1 20 1 30 1 40 1 50 -1