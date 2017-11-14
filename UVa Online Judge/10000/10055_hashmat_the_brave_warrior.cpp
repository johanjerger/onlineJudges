#include <iostream>

using namespace std;

int main()
{
  long team_a, team_b;
  while(cin >> team_a >> team_b)
    cout << abs(team_a - team_b) << endl;
  return 0;
}
