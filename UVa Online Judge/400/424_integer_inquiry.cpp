#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	vector<string> numbers;
  string number, result;
  while(getline(cin, number) && number != "0") {
    numbers.push_back(number);
  }

  result = numbers[0];
  for (int i=1; i < numbers.size(); i++) {
    if(result.size() > numbers[i].size())
      numbers[i] = string(result.size() - numbers[i].size(), '0') + numbers[i];
    else result = string(numbers[i].size() - result.size(), '0') + result;
    int rest = 0;
    for (int j = result.size() - 1; j >= 0; j--) {
      int num = 0;
      num = (result[j] - '0') + (numbers[i][j] - '0') + rest;
      if (num > 9) {
        rest = 1;
        num -= 10;
      } else {
        rest = 0;
      }
      result.replace(j, 1, to_string(num));
    }
    if (rest == 1) result = "1" + result;
  }
  cout << result << endl;
	return 0;
}
