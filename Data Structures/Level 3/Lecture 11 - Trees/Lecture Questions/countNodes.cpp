#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>

class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
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
    cout << "Enter root data : " << endl;
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

int countNodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int answer = 1; // for root
    for (int i = 0; i < root->children.size(); i++)
    {
        answer += countNodes(root->children.at(i));
    }
    return answer;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    cout << countNodes(root) << endl;
    return 0;
}

// 1 3 2 3 4 2 5 6 1 7 1 8 0 0 0 0