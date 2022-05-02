#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void zigZagOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<BinaryTreeNode<int> *> q, s;
    q.push(root);
    int level = 1;
    while (!q.empty() || !s.empty())
    {
        if (level % 2 != 0)
        {
            if (!q.empty())
            {
                BinaryTreeNode<int> *front = q.top();
                cout << front->data << " ";
                if (front->left)
                {
                    s.push(front->left);
                }
                if (front->right)
                {
                    s.push(front->right);
                }
                q.pop();
            }
            else
            {
                if (!s.empty())
                {
                    level += 1;
                    cout << endl;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            if (!s.empty())
            {
                BinaryTreeNode<int> *top = s.top();
                cout << top->data << " ";
                if (top->right)
                {
                    q.push(top->right);
                }
                if (top->left)
                {
                    q.push(top->left);
                }
                s.pop();
            }
            else
            {
                if (!q.empty())
                {
                    level += 1;
                    cout << endl;
                }
                else
                {
                    break;
                }
            }
        }
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    zigZagOrder(root);
}