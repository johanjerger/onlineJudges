#include <iostream>
#include <map>

using namespace std;

int main ()
{
  int test_cases, count;
  long int number;
  bool error;
  map<long int, bool> exist;

  cin >> test_cases, cin.ignore();
  while (test_cases--) {
    error = false;
    cin >> count, cin.ignore();
    while (count--) {
      cin >> number, cin.ignore();
      if (exist.count(number) == 0) exist.insert({number, true});
      else {
        cout << number << endl;
        error = true;
      }
    }
    if (!error) cout << "Not found!" << endl;
    exist.clear();
  }
}
