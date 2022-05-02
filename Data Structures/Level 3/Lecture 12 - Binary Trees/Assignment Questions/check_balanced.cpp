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
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

class Balanced
{
public:
    int height;
    bool answer;
};

Balanced *isBalancedHelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Balanced *p = new Balanced;
        p->height = 0;
        p->answer = true;
        return p;
    }

    Balanced *left_answer = isBalancedHelper(root->left);
    Balanced *right_answer = isBalancedHelper(root->right);

    bool flag;

    if ((!left_answer->answer) || (!right_answer->answer) || (abs(left_answer->height - right_answer->height) > 1))
    {
        flag = false;
    }
    else
    {
        flag = true;
    }

    Balanced *output = new Balanced;
    output->height = max(left_answer->height, right_answer->height) + 1;
    output->answer = flag;

    return output;
}

bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    return isBalancedHelper(root)->answer;
}

// int height(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }
//     int answer = 0;
//     int l = height(root->left);
//     int r = height(root->right);
//     answer = (l > r) ? (l) : (r);
//     return answer + 1;
// }

// bool isBalanced(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//     {
//         return true;
//     }

//     int l = height(root->left);
//     int r = height(root->right);

//     if (abs(l - r) > 1)
//     {
//         return false;
//     }
//     return (isBalanced(root->left) && isBalanced(root->right));
// }

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << (isBalanced(root) ? "true" : "false");
}