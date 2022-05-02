#include <iostream>
using namespace std;

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

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
}

Node *insertNode(Node *head, int index, int data)
{
    Node *temp = head;
    int count = 0;
    Node *newNode = new Node(data);
    if (index == 0)
    {
        newNode->next = temp;
        head = newNode;
        return head;
    }
    while (temp != NULL && count < index - 1)
    {
        count++;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        int pos, data;
        cin >> pos >> data;
        head = insertNode(head, pos, data);
        print(head);
    }
}