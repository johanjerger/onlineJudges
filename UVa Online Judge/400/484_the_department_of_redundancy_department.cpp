#include <iostream>
#include <sstream>
#include <queue>
#include <map>

using namespace std;

int main()
{
  int number;
  map<int, int> occurences;
  queue<int> order;

  while (cin >> number) {
    if ( occurences.count(number) == 0 ){
      occurences[number] =  1;
      order.push(number);
    } else {
      occurences[number]++;
    }
  }

  while (!order.empty()) {
    number = order.front();
    order.pop();
    cout << number << ' ' << occurences.at(number) << endl;
  }

  return 0;
}
