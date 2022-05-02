#include <iostream>
using namespace std;

bool checkMember(int n)
{
  int a = 0, b = 1, c;
  c = a + b;
  while (n != a)
  {
    a = b;
    b = c;
    c = a + b;
    if (n < a)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  int n;
  cin >> n;
  if (checkMember(n))
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }
  return 0;
}