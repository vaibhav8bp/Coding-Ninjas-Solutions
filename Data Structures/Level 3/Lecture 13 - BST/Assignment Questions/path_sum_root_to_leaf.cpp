#include <iostream>
#include <vector>
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

    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
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

void helper(BinaryTreeNode<int> *root, int k, vector<int> output)
{
    if (root == NULL)
    {
        return;
    }
    else if (!root->left && !root->right)
    {
        if (k - root->data == 0)
        {
            for (int i = 0; i < output.size(); i++)
            {
                cout << output.at(i) << " ";
            }
            cout << root->data << endl;
        }
        return;
    }

    output.push_back(root->data);

    helper(root->left, k - root->data, output);
    helper(root->right, k - root->data, output);
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    vector<int> output;
    helper(root, k, output);
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
}