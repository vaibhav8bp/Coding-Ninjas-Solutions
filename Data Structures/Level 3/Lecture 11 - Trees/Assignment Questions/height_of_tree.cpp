#include <iostream>
#include <queue>
#include <vector>
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

int getHeight(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int answer = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int smallanswer = getHeight(root->children.at(i));
        if (answer < smallanswer)
        {
            answer = smallanswer;
        }
    }
    return 1 + answer;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    cout << getHeight(root);
}