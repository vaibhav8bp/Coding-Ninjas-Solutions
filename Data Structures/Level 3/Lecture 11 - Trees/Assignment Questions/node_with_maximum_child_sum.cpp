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

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    TreeNode<int> *max_sum;
    int previous_sum = INT_MIN;
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *front = q.front();
        int currentsum = front->data;
        for (int i = 0; i < front->children.size(); i++)
        {
            currentsum += front->children.at(i)->data;
            q.push(front->children.at(i));
        }
        if (currentsum > previous_sum)
        {
            previous_sum = currentsum;
            max_sum = front;
        }
        q.pop();
    }
    return max_sum;
}

// TreeNode<int>* maxSumNode(TreeNode<int> *root)
// {
//     TreeNode<int> *ans = root;
//     int sum = root->data;
//     for (int i = 0; i < root->children.size(); i++) ///  sum for root node
//     {
//         sum += root->children[i]->data;
//     }

//     for (int i = 0; i < root->children.size(); i++)
//     {
//         TreeNode<int> *childmax = maxSumNode(root->children[i]); // get the max node using recursion

//         int smallsum = childmax->data;

//         for (int i = 0; i < childmax->children.size(); i++) // calculating sum for max node
//         {
//             smallsum += childmax->children[i]->data;
//         }

//         if (sum <= smallsum) // comparision  update if necessary
//         {
//             ans = childmax;
//             sum = smallsum;
//         }
//     }
//     return ans;
// }

// template <typename T>

// class MaxPair
// {
// public:
//     TreeNode<T> *node;
//     int sum;
// };

// MaxPair<int> *maxSumNodeHelper(TreeNode<int> *root)
// {
//     if (root == NULL)
//     {
//         MaxPair<int> *initial = new MaxPair<int>();
//         initial->node = NULL;
//         initial->sum = INT_MIN;
//         return initial;
//     }
//     int current_sum = root->data;
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         current_sum += root->children.at(i)->data;
//     }

//     MaxPair<int> *initial = new MaxPair<int>();
//     initial->node = root;
//     initial->sum = current_sum;
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         MaxPair<int> *answer = maxSumNodeHelper(root->children.at(i));
//         if (answer->sum > initial->sum)
//         {
//             initial = answer;
//         }
//     }
//     return initial;
// }

// TreeNode<int> *maxSumNode(TreeNode<int> *root)
// {
//     return maxSumNodeHelper(root)->node;
// }

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    TreeNode<int> *ans = maxSumNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
}