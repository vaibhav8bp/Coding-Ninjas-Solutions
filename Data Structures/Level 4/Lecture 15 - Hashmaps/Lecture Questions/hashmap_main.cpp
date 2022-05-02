#include <iostream>
using namespace std;

template <typename V>

class MapNode
{
public:
    string key;
    V value;
    MapNode *next;
    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    ~MapNode()
    {
        delete next;
    }
};

template <typename V>

class ourMap
{
    MapNode<V> **buckets;
    int count;
    int numBuckets;
    int getBucketIndex(string key)
    {
        // Base p with respect to a string
        int hashCode = 0;
        int currentCoeff = 1;

        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            hashCode %= numBuckets;
            currentCoeff *= 37; // 37 by choice
            currentCoeff %= numBuckets;
        }
        return hashCode % numBuckets;
    }

    void reHash()
    {
        MapNode<V> **temp = buckets;
        buckets = new MapNode<V> *[2 * numBuckets];
        for (int i = 0; i < 2 * numBuckets; i++)
        {
            buckets[i] = NULL;
        }
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;
        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

public:
    ourMap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }
    ~ourMap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }
    void getLoadFactor()
    {
        cout << count << " / " << numBuckets << endl;
    }
    int size()
    {
        return count;
    }
    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        // Insertion at beginning
        double loadFactor = ((float)count) / numBuckets;
        if (loadFactor > 0.7)
        {
            reHash();
        }
    }
    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V delete_value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return delete_value;
            }
            prev = head;
            head = head->next;
        }
        return 0; // Optional
    }
};

int main()
{
    ourMap<int> map;
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key += c;
        int value = i + 1;
        map.insert(key, value);
        map.getLoadFactor();
    }
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key += c;
        cout << key << " : " << map.getValue(key) << endl;
    }
    cout << "Size before deleting : " << map.size() << endl;
    map.remove("abc2");
    map.remove("abc7");
    cout << "Size after deleting : " << map.size() << endl;
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key += c;
        cout << key << " : " << map.getValue(key) << endl;
    }
    return 0;
}