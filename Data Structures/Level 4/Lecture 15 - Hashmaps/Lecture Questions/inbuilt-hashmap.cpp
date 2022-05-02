#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
int main()
{
    unordered_map<string, int> ourMap;
    // Insertion
    pair<string, int> p("abc", 1);
    ourMap.insert(p);
    // Find or Access
    cout << ourMap["abc"] << endl;
    cout << ourMap.at("abc") << endl;
    // size
    cout << ourMap.size() << endl;
    // erase
    cout << ourMap.erase("def") << endl;
    cout << ourMap.size() << endl;
    return 0;
}