#include <iostream>
#include <sstream>

using namespace std;

int main()
{
  int diffs[3005], count, i;

  while (getline(cin, input) && !input.empty()) {
    i = 0;
    count = 0;
    stringstream numbers(input);

    input >> diffs[i++];
    count ++;
    while (input >> diffs[i]) {
      diffs[i] = abs(diffs[i] - diffs[i-1]);
      i++;
      count++;
    }

    for (int j = 0; j < count; j++) {
      if (diffs[j] < count)
    }
  }

}
