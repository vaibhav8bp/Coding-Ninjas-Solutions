#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
    vector<int> pq;
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

public:
    PriorityQueue()
    {
    }
    int removeMin()
    {
        if (pq.empty())
        {
            return -1;
        }
        int delete_value = pq.at(0);
        pq.at(0) = pq.at(pq.size() - 1);
        pq.pop_back();
        int parentIndex = 0;
        int left_child_Index = (2 * parentIndex + 1);
        int right_child_Index = (2 * parentIndex + 2);
        int minIndex;
        while (left_child_Index < pq.size())
        {
            if (right_child_Index >= pq.size())
            {
                minIndex = left_child_Index;
            }
            else
            {
                minIndex = ((pq.at(left_child_Index)) < (pq.at(right_child_Index))) ? (left_child_Index) : (right_child_Index);
            }

            if (pq.at(minIndex) > pq.at(parentIndex))
            {
                break;
            }
            else
            {
                swap(&pq.at(parentIndex), &pq.at(minIndex));
                parentIndex = minIndex;
            }
            left_child_Index = (2 * parentIndex + 1);
            right_child_Index = (2 * parentIndex + 2);
        }
        return delete_value;
    }

    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if ((pq.at(parentIndex) > pq.at(childIndex)))
            {
                swap(&pq.at(parentIndex), &pq.at(childIndex));
                childIndex = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    bool isEmpty()
    {
        return pq.empty();
    }
    int getSize()
    {
        return pq.size();
    }
    int getMin()
    {
        if (pq.empty())
        {
            return 0;
        }
        return pq.at(0);
    }
};

int main()
{
    return 0;
}