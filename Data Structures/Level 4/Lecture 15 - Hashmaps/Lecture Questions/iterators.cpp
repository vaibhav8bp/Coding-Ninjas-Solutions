#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    unordered_map<string, int> ourMap;
    ourMap["abc"] = 1;
    ourMap["abc1"] = 2;
    ourMap["abc2"] = 3;
    ourMap["abc3"] = 4;
    ourMap["abc4"] = 5;
    ourMap["abc5"] = 6;
    unordered_map<string, int>::iterator it;
    it = ourMap.begin();
    while (it != ourMap.end())
    {
        cout << "Key : " << it->first << ", Value : " << it->second << endl;
        it++;
    }
    return 0;
}