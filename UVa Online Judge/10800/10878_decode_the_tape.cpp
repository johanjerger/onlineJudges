#include <iostream>
#include <math.h>

using namespace std;

int main ()
{
  string trash, str;
  char ch;
  getline(cin, trash);
  while (getline(cin, str) && str != "___________") {
    ch = 0;
    int pos = 8;
    for (int i=0; i < str.size(); i++) {
      if (str[i] == '|' || str[i] == ' ') continue;
      if (str[i] == '.') {pos = 9; continue;}
      if(str[i] == 'o') ch += pow(2, pos-i);
    }
    cout << ch;
  }

	return 0;
}
