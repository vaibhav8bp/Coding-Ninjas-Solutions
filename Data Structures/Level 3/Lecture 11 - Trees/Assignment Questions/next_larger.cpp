#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int n)
{
    if (root == NULL)
    {
        return root;
    }
    TreeNode<int> *nextLarger = NULL;
    if (root->data > n)
    {
        nextLarger = root;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *temp = getNextLargerElement(root->children[i], n);
        if (nextLarger == NULL)
        {
            nextLarger = temp;
        }
        else if (temp != NULL && temp->data < nextLarger->data)
        {
            nextLarger = temp;
        }
    }
    return nextLarger;
}

// TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }

//     queue<TreeNode<int> *> q;
//     int distance = INT_MAX;

//     TreeNode<int> *answer = NULL;
//     if (root->data > x && (root->data - x < distance))
//     {
//         distance = root->data - x;
//         answer = root;
//     }

//     q.push(root);

//     while (!q.empty())
//     {
//         TreeNode<int> *front = q.front();
//         for (int i = 0; i < front->children.size(); i++)
//         {
//             if (front->children.at(i)->data > x && (front->children.at(i)->data - x < distance))
//             {
//                 answer = front->children.at(i);
//                 distance = front->children.at(i)->data - x;
//             }
//             q.push(front->children.at(i));
//         }
//         q.pop();
//     }
//     return answer;
// }

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    int x;
    cin >> x;
    TreeNode<int> *ans = getNextLargerElement(root, x);

    if (ans != NULL)
    {
        cout << ans->data;
    }
}