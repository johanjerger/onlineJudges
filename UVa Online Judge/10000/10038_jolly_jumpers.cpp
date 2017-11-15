#include <iostream>

using namespace std;

int main()
{
  int numbers, diffs[3005];
  bool not_jolly;

  while (cin >> numbers) {
      not_jolly = true;
      cin >> diffs[0];
      for (int i=1; i < numbers; i++) {
        cin >> diffs[i];
        diffs[i-1] = abs(diffs[i-1] - diffs[i]);
      }
      cin.ignore();

      for (int i=0; i < numbers-1; i++) {
        not_jolly &= (diffs[i] == 0 || diffs[i] >= numbers);
        cout << diffs[i] << ' ';
      }

      string res = (not_jolly) ? "Not jolly" : "Jolly";
      cout << res << endl;
  }

  return 0;
}
