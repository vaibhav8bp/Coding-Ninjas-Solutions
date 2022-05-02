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
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root)
{
    pair<int, int> answer;
    answer.first = INT_MAX;
    answer.second = INT_MIN;

    if (root == NULL)
    {
        return answer;
    }

    pair<int, int> left_answer = getMinAndMax(root->left);
    pair<int, int> right_answer = getMinAndMax(root->right);

    answer.first = min(root->data, min(left_answer.first, right_answer.first));
    answer.second = max(root->data, max(left_answer.second, right_answer.second));

    return answer;
}

// pair<int, int> getMinAndMax(BinaryTreeNode<int> *root)
// {
//     pair<int, int> answer;
//     answer.first = INT_MAX;
//     answer.second = INT_MIN;
//     queue<BinaryTreeNode<int> *> pendingNodes;
//     pendingNodes.push(root);
//     while (!pendingNodes.empty())
//     {
//         BinaryTreeNode<int> *front = pendingNodes.front();
//         if (front->data > answer.second)
//         {
//             answer.second = front->data;
//         }
//         if (front->data < answer.first)
//         {
//             answer.first = front->data;
//         }
//         if (front->right)
//         {
//             pendingNodes.push(front->right);
//         }
//         if (front->left)
//         {
//             pendingNodes.push(front->left);
//         }
//         pendingNodes.pop();
//     }
//     return answer;
// }

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}