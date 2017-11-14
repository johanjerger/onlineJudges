#include <iostream>
#include <vector>

using namespace std;

int trim_size(const string row)
{
  int trimed = 0;
  for (int i = 0; i < row.length(); i++)
    if (row[i] != ' ') trimed++;
  return trimed;
}

int main ()
{
  int rows, void_space, max;
  string row;
  while (cin >> rows && rows != 0) {
    cin.ignore();
    vector<int> voids;
    void_space = max = 0;
    while (rows--) {
      getline(cin, row);
      int trimed_size = trim_size(row);
      if (trimed_size > max) max = trimed_size;
      voids.push_back(trimed_size);
    }
    for (int i = 0; i < voids.size(); i++)
      void_space += (max - voids[i]);
    cout << void_space << endl;
  }
}
