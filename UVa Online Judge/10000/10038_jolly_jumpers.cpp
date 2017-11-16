#include <iostream>
#include <set>

using namespace std;

int main()
{
  int numbers, seq[3005], diffs[3005];
  set <int> differences;
  bool is_jolly;

  while (cin >> numbers) {
      is_jolly = true;
      cin >> seq[0];
      for (int i=1; i < numbers; i++) {
        cin >> seq[i];
        diffs[i-1] = abs(seq[i] - seq[i-1]);
        differences.insert(abs(seq[i] - seq[i-1]));
      }
      cin.ignore();

      for (int i=0; i < numbers-1; i++)
        is_jolly &= (diffs[i] >= 1 && diffs[i] <= numbers-1);

      for (int i=1; i <= numbers-1; i++)
        is_jolly = (is_jolly && (differences.find(i) != differences.end()));

      string res = (is_jolly) ? "Jolly" : "Not jolly";
      cout << res << endl;
      differences.clear();
  }

  return 0;
}
