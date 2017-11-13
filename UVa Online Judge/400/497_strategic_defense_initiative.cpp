#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> sequence;
vector<int> result;

void lis()
{

}

int main ()
{
  int test_cases;
  string input;
  vector<int> result;

  cin >> test_cases, cin.ignore();
  cin.ignore();
  while (test_cases--)
  {
    while (getline(cin, input) && !input.empty()) {
      sequence.push_back(atoi(input.c_str()));
    }

    lis();

    sequence.clear();
  }
}
