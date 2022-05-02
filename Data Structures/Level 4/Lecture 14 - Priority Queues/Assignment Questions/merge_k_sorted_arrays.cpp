#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, pair<int, int>> ppi;

vector<int> mergeKSortedArrays(vector<vector<int> *> input)
{
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    for (int i = 0; i < input.size(); i++)
    {
        ppi initial;
        initial.first = input.at(i)->at(0);
        initial.second.first = i;
        initial.second.second = 0;
        pq.push(initial);
    }
    vector<int> output;
    while (!pq.empty())
    {
        ppi current = pq.top();
        pq.pop();
        int array_number = current.second.first;
        int array_index = current.second.second;
        output.push_back(current.first);
        if (array_index + 1 < input.at(array_number)->size())
        {
            ppi final;
            final.first = input.at(array_number)->at(array_index + 1);
            final.second.first = array_number;
            final.second.second = array_index + 1;
            pq.push(final);
        }
    }
    return output;
}

// O(n^2)
/*
vector<int> mergeKSortedArrays(vector<vector<int> *> input)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input.at(i)->size(); j++)
        {
            pq.push(input.at(i)->at(j));
        }
    }
    vector<int> output;
    while (!pq.empty())
    {
        output.push_back(pq.top());
        pq.pop();
    }
    return output;
}
*/
int main()
{
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++)
    {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++)
        {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }

    return 0;
}