#include <iostream>
#include <queue>
#include <climits>
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

bool isBSTHelper(BinaryTreeNode<int> *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < min || root->data > max)
    {
        return false;
    }
    bool isLeft = isBSTHelper(root->left, min, root->data - 1);
    bool isRight = isBSTHelper(root->right, root->data, max);

    return isLeft && isRight;
}

bool isBST(BinaryTreeNode<int> *root)
{
    return isBSTHelper(root, INT_MIN, INT_MAX);
}

// class BST
// {
// public:
//     int minimum;
//     int maximum;
//     bool answer;
// };

// BST isBSTHelper(BinaryTreeNode<int> *root)
// {
//     BST b;
//     if (root == NULL)
//     {
//         b.minimum = INT_MAX;
//         b.maximum = INT_MIN;
//         b.answer = true;
//         return b;
//     }

//     BST l = isBSTHelper(root->left);
//     BST r = isBSTHelper(root->right);

//     int mi = min(root->data, min(l.minimum, r.minimum));
//     int ma = max(root->data, max(l.maximum, r.maximum));

//     bool final = (root->data > l.maximum) && (root->data <= r.minimum) && (l.answer) && (r.answer);

//     b.minimum = mi;
//     b.maximum = ma;
//     b.answer = final;
//     return b;
// }

// bool isBST(BinaryTreeNode<int> *root)
// {
//     return isBSTHelper(root).answer;
// }

// int maximum(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//     {
//         return INT_MIN;
//     }
//     return max(root->data, max(maximum(root->left), maximum(root->right)));
// }

// int minimum(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//     {
//         return INT_MAX;
//     }
//     return min(root->data, min(minimum(root->left), minimum(root->right)));
// }

// bool isBST(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//     {
//         return true;
//     }

//     int left_max = maximum(root->left);
//     int right_min = minimum(root->right);

//     bool output = (root->data > left_max) && (root->data <= right_min) && (isBST(root->left)) && (isBST(root->right));
//     return output;
// }

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}