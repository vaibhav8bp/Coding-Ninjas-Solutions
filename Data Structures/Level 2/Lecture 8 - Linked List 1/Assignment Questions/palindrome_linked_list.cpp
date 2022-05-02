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

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }

    int midPoint = (count - 1) / 2;

    int i = 0;
    temp = head;
    Node *previous = NULL;
    while (i <= midPoint)
    {
        previous = temp;
        temp = temp->next;
        i++;
    }
    previous->next = NULL;
    Node *secondHead = reverseLinkedList(temp);
    Node *current = head;
    while (secondHead != NULL)
    {
        if (current->data != secondHead->data)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        bool ans = isPalindrome(head);

        if (ans)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }

    return 0;
}