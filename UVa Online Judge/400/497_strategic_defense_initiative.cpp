#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

int main ()
{
  int test_cases, misil;
  string input;
  vector<int> sequence;

  cin >> test_cases, cin.ignore(), cin.ignore();
  while (test_cases--)
  {
    while (getline(cin, input) && !input.empty()) {
        stringstream ss(input);
        ss >> misil;
        sequence.push_back(misil);
    }

    vector<int> LIS(sequence.size(), 1);
    vector<int> path(sequence.size(), -1);
    LIS[0] = 1;

    for (int i = 1; i < sequence.size(); ++i)
      for (int j = 0; j < i; ++j) {
          int l = (sequence[j] < sequence[i]) ? LIS[j] + 1 : 0;
          if (l > LIS[i]) LIS[i] = l, path[i] = static_cast<int>(j);
      }

    int i = static_cast<int>(distance(LIS.begin(), max_element(LIS.begin(), LIS.end())));

    vector<int> print(1, sequence[i]);
    while (path[i] != -1) {
        i = path[i];
        print.insert(print.begin(), sequence[i]);
    }

    cout << "Max hits: " << print.size() << endl;
    copy(print.begin(), print.end(), ostream_iterator<int>(cout, "\n"));

    if (test_cases) cout << endl;
    sequence.clear();
  }
}
