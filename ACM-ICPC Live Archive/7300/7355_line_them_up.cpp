#include <iostream>
#include <sstream>

using namespace std;

int main()
{
  int n = 0, flag = 0;
  string input, name, next_name;

  while (getline(cin, input) && !input.empty()) {
      n = atoi(input.c_str());

      getline(cin, name);
      getline(cin, next_name);

      flag = (name < next_name) ?  1 : -1;

      for (int i=2; i < n; i++) {
        name = next_name;
        getline(cin, next_name);
        if (flag != 0){
            if (name < next_name && flag != 1) flag = 0;
            if (name > next_name && flag != -1) flag = 0;
        }
      }

      if (flag == 1)  cout << "INCREASING" << endl;
      if (flag == 0)  cout << "NEITHER" << endl;
      if (flag == -1) cout << "DECREASING" << endl;
  }

  return 0;
}
