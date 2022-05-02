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

bool isPresent(TreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        bool answer = isPresent(root->children.at(i), x);
        if (answer)
        {
            return true;
        }
    }
    return false;
}

/*
bool isPresent(TreeNode<int>*root,int x)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==x)
    {
        return true;
    }
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
        TreeNode<int>*front=pendingNodes.front();
        pendingNodes.pop();
        for(int i=0;i<front->children.size();i++)
        {
            if(front->children.at(i)->data==x)
            {
                return true;
            }
            pendingNodes.push(front->children.at(i));
        }
    }
    return false;
}
*/

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    int x;
    cin >> x;
    cout << (isPresent(root, x) ? "true" : "false");
}