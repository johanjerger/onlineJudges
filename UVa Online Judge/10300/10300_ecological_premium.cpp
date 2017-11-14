#include <iostream>

using namespace std;

int main()
{
  int test_cases, farmers_count, total;
  int size, animals, env_friendliness;
  cin >> test_cases, cin.ignore();
  while (test_cases--) {
    total = 0;
    cin >> farmers_count, cin.ignore();
    while (farmers_count--) {
      cin >> size >> animals >> env_friendliness, cin.ignore();
      total += size * env_friendliness;
    }
    cout << total << endl;
  }
  return 0;
}
