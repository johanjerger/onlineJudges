#include <iostream>
#include <map>

using namespace std;

int main()
{
  int jack_cds, jill_cds, cd_number, result = 0;
  map<int, bool> both_own;
  string trash;

  while (true) {
    cin >> jack_cds >> jill_cds, cin.ignore();

    if (!jack_cds && !jill_cds) break;

    while (jack_cds--) {
      cin >> cd_number, cin.ignore();
      both_own.insert( {cd_number, false} );
    }

    while (jill_cds--) {
      cin >> cd_number, cin.ignore();
      if ( both_own.find(cd_number) != both_own.end() ) result++;
    }

    cout << result << endl;
    both_own.clear();
    result = 0;
  }
}
