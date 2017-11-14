#include <iostream>

using namespace std;

int main ()
{
  string str;
  while (getline(cin, str) && !str.empty()) {
    for(int i=0; i < str.length(); i++)
      str[i] -= 7;
    cout << str << endl;
  }
}
