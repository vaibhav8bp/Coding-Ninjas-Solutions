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

Node *kReverse(Node *head, int k)
{
    if (head == NULL || k == 0 || k == 1)
    {
        return head;
    }
    Node *startNode = head, *currentNode = head, *temp, *newHead;
    int count;
    bool firstTime = true;

    while (currentNode != NULL)
    {
        count = 0;
        Node *tempHead = currentNode, *previousNode = NULL;
        while (count < k && currentNode != NULL)
        {
            temp = currentNode->next;
            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = temp;
            count++;
        }
        // This is connecting earlier chain
        startNode->next = previousNode;
        // This is connecting later chain
        tempHead->next = currentNode;
        startNode = tempHead;

        if (firstTime)
        {
            newHead = previousNode;
            firstTime = false;
        }
    }
    return newHead;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        int k;
        cin >> k;
        head = kReverse(head, k);
        print(head);
    }

    return 0;
}