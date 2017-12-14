#include <iostream>
#include <math.h>

using namespace std;

typedef pair<int,int> point;

int main ()
{
  int test_cases, r1x1, r1y1, r1x2, r1y2, r2x1, r2y1, r2x2, r2y2, h, i, j, k;
  cin >> test_cases, cin.ignore();
  while (test_cases--) {
    cin >> r1x1 >> r1y1 >> r1x2 >> r1y2, cin.ignore();
    cin >> r2x1 >> r2y1 >> r2x2 >> r2y2, cin.ignore();
    h = max(r1x1, r2x1); i = max(r1y1, r2y1); j = min(r1x2, r2x2); k = min(r1y2, r2y2);
    if (h >= j || i >= k) cout << "No Overlap" << endl;
    else cout << h << ' ' << i << ' ' << j << ' ' << k << endl;
    if (test_cases) cout << endl;
  }
}
