#include <iostream>

using namespace std;

int main()
{
  int test_cases, days, parties;
  int hartals[105];

  cin >> test_cases, cin.ignore();
  while (test_cases--) {
    int lose_days = 0;
    cin >> days, cin.ignore();
    cin >> parties, cin.ignore();
    for (int i = 0; i < parties; i++)
      cin >> hartals[i], cin.ignore();

    // input ended

    for (int i = 1; i <= days; i++) {
      int is_weekly_holiday = i % 7;
      if (is_weekly_holiday == 0 || is_weekly_holiday == 6) continue;
      bool lost_day = true;
      for (int j = 0; j < parties; j++)
        if (i % hartals[j] == 0) lost_day = false;
      if (!lost_day) lose_days++;
    }
    cout << lose_days << endl;
  }
}
