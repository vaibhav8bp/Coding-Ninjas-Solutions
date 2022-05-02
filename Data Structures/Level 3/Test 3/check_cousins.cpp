#include <iostream>
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
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
}

int depth(BinaryTreeNode<int> *root, int node)
{
    if (!root)
    {
        return -1;
    }
    if (root->data == node)
    {
        return 0;
    }
    int left_answer = depth(root->left, node);
    if (left_answer != -1)
    {
        return 1 + left_answer;
    }
    int right_answer = depth(root->right, node);
    if (right_answer != -1)
    {
        return 1 + right_answer;
    }
    return -1;
}

bool isSibling(BinaryTreeNode<int> *root, int p, int q)
{
    if (!root || (!root->left && !root->right))
    {
        return false;
    }
    if (root->left && root->right)
    {
        if (root->left->data == p && root->right->data == q)
        {
            return true;
        }
        else if (root->right->data == q && root->left->data == p)
        {
            return true;
        }
        else
        {
            return isSibling(root->left, p, q) || isSibling(root->right, p, q);
        }
    }
    if (root->left && !root->right)
    {
        return isSibling(root->left, p, q);
    }
    else if (!root->left && root->right)
    {
        return isSibling(root->right, p, q);
    }
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q)
{
    if (!root)
    {
        return false;
    }
    return (depth(root, p) == depth(root, q)) && (!isSibling(root, p, q));
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int n1, n2;
    cin >> n1 >> n2;
    if (isCousin(root, n1, n2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}