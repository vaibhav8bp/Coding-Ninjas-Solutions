#include <iostream>
#include <vector>
#include <climits>
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
    int removeMax()
    {
        if (pq.empty())
        {
            return INT_MIN;
        }
        int delete_value = pq.at(0);
        pq.at(0) = pq.at(pq.size() - 1);
        pq.pop_back();
        int parentIndex = 0;
        int left_child_Index = (2 * parentIndex + 1);
        int right_child_Index = (2 * parentIndex + 2);
        while (left_child_Index < pq.size())
        {
            int maxIndex = parentIndex;
            if (right_child_Index < pq.size())
            {
                maxIndex = ((pq.at(left_child_Index)) > (pq.at(right_child_Index))) ? (left_child_Index) : (right_child_Index);
            }
            else
            {
                maxIndex = left_child_Index;
            }

            if (pq.at(maxIndex) < pq.at(parentIndex))
            {
                break;
            }
            else
            {
                swap(&pq.at(parentIndex), &pq.at(maxIndex));
                parentIndex = maxIndex;
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
            if ((pq.at(parentIndex) < pq.at(childIndex)))
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
    int getMax()
    {
        if (pq.empty())
        {
            return INT_MIN;
        }
        return pq.at(0);
    }
};

int main()
{
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1)
    {
        switch (choice)
        {
        case 1: // insert
            int element;
            cin >> element;
            pq.insert(element);
            break;
        case 2: // getMax
            cout << pq.getMax() << "\n";
            break;
        case 3: // removeMax
            cout << pq.removeMax() << "\n";
            break;
        case 4: // size
            cout << pq.getSize() << "\n";
            break;
        case 5: // isEmpty
            cout << (pq.isEmpty() ? "true\n" : "false\n");
        default:
            return 0;
        }

        cin >> choice;
    }
}