#include <iostream>
#include <sstream>

using namespace std;

int main()
{
  int diffs[3005], i, j;
  string input, result;

  while (getline(cin, input) && !input.empty()) {
    i = 0;
    stringstream numbers(input.c_str());

    numbers >> diffs[i++];
    while (numbers >> diffs[i]) {
      diffs[i-1] = abs(diffs[i-1] - diffs[i]);
      i++;
    }

    for (j = 0; j < i-1; j++) {
      if (diffs[j] > i-1 || diffs[j] == 0) break;
    }

    if (j == i) j--;
    result = (diffs[j] > i-1 || diffs[j] == 0) ? "Not jolly" : "Jolly";
    cout << result << endl;
  }

  return 0;
}
