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

Node *appendLastNToFirst(Node *head, int n)
{
    if (n == 0 || head == NULL)
    {
        return head;
    }
    Node *tail = head;
    Node *newhead = NULL;
    int count = 1;
    while (tail->next != NULL)
    {
        count++;
        tail = tail->next;
    }
    // count refers to the total length of linked list
    // tail refers to the last node of the original linked list
    // a refers to the index of last node of the updated linked list.
    int a = count - n - 1;
    // if n is greater than or equal to the size of the linked list updated linked list would be empty according to question.
    if (a <= 0)
    {
        return NULL;
    }
    
    int i = 0;
    Node *temp = head;
    while (i < a)
    {
        i++;
        temp = temp->next;
    }
    // temp refers to the last node of the updated linked list.
    newhead = temp->next;
    tail->next = head;
    temp->next = NULL;
    head = newhead;
    tail = temp;
    /*
    cout << head->data << endl;
    cout << tail->data << endl;
    */
    return head;
}

/*

Node *appendLastNToFirst(Node *head, int n)
{
    if(n==0 || head==NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    Node *temp = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    temp = slow->next;
    slow->next = NULL;
    fast->next = head;
    return temp;
}

*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int n;
        cin >> n;
        head = appendLastNToFirst(head, n);
        print(head);
    }
    return 0;
}