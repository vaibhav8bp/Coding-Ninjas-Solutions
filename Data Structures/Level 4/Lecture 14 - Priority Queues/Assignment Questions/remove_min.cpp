#include <iostream>
#include <climits>
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
    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }

        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }

            childIndex = parentIndex;
        }
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
        case 2: // getMin
            cout << pq.getMin() << "\n";
            break;
        case 3: // removeMax
            cout << pq.removeMin() << "\n";
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