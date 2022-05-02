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

template <typename T>
class Pair
{
public:
    TreeNode<T> *largest;
    TreeNode<T> *second_largest;
    Pair(TreeNode<T> *first, TreeNode<T> *second)
    {
        this->largest = first;
        this->second_largest = second;
    }
};

Pair<int> *getSecondLargestNodeHelper(TreeNode<int> *root)
{
    // if (root == NULL)
    // {
    //     return new Pair<int>(NULL, NULL);
    // }
    Pair<int> *answer = new Pair<int>(root, NULL);
    for (int i = 0; i < root->children.size(); i++)
    {
        Pair<int> *child_answer = getSecondLargestNodeHelper(root->children.at(i));
        if (child_answer->largest->data > answer->largest->data)
        {
            if (child_answer->second_largest == NULL)
            {
                answer->second_largest = answer->largest;
            }
            else
            {
                if (child_answer->second_largest->data > answer->largest->data)
                {
                    answer->second_largest = child_answer->second_largest;
                }
                else
                {
                    answer->second_largest = answer->largest;
                }
            }
            answer->largest = child_answer->largest;
        }
        else
        {
            if (answer->largest->data > child_answer->largest->data && (answer->second_largest == NULL || child_answer->largest->data > answer->second_largest->data))
            {
                answer->second_largest = child_answer->largest;
            }
        }
    }
    return answer;
}

TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    return getSecondLargestNodeHelper(root)->second_largest;
}

// TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }
//     queue<TreeNode<int> *> q;
//     q.push(root);
//     TreeNode<int> *max = root, *smallmax = NULL;
//     int second_largest = INT_MIN;
//     while (!q.empty())
//     {
//         TreeNode<int> *front = q.front();
//         for (int i = 0; i < front->children.size(); i++)
//         {
//             if (max->data < front->children.at(i)->data)
//             {
//                 smallmax = max;
//                 max = front->children.at(i);
//                 second_largest = smallmax->data;
//             }
//             else if (second_largest < front->children.at(i)->data && max->data > front->children.at(i)->data)
//             {
//                 smallmax = front->children.at(i);
//             }
//             q.push(front->children.at(i));
//         }
//         q.pop();
//     }
//     return smallmax;
// }

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    TreeNode<int> *ans = getSecondLargestNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
    else
    {
        cout << INT_MIN;
    }
}