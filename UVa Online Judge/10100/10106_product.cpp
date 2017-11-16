#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	string number, multiplier, result, mult_result;
  vector <string> numbers, mult;
	int rest, res;
  while (cin >> number >> multiplier) {
    mult_result = "";
    for (int i=multiplier.size()-1; i >= 0; i--) {
      rest = res = 0;
      for (int j = number.size()-1; j >=0; j--) {
        res = ((multiplier[i] - '0') * (number[j] - '0')) + rest;
        if (res > 9) {
          rest = (int) res/10;
          res %= 10;
        } else {
          rest = 0;
        }
        if(mult_result.empty()) mult_result = to_string(res);
        else mult_result = to_string(res) + mult_result;
      }
      if(rest != 0) mult_result = to_string(rest) + mult_result;
      mult_result += string(numbers.size(), '0');
      numbers.push_back(mult_result);
      mult_result = "";
    }

    result = numbers[0];
    for (int i=1; i < numbers.size(); i++) {
      if(result.size() > numbers[i].size())
        numbers[i] = string(result.size() - numbers[i].size(), '0') + numbers[i];
      else result = string(numbers[i].size() - result.size(), '0') + result;
      rest = res = 0;
      for (int j = result.size() - 1; j >= 0; j--) {
        res = (result[j] - '0') + (numbers[i][j] - '0') + rest;
        if (res > 9) {
          rest = 1;
          res -= 10;
        } else {
          rest = 0;
        }
        result.replace(j, 1, to_string(res));
      }
      if (rest == 1) result = "1" + result;
    }
    for (int i = 0; i < result.size(); i++) {
      if (result[i] != '0') break;
      result.erase(0,1);
      i--;
    }
    if (result.empty()) cout << "0" << endl;
    else cout << result << endl;
    numbers.clear();
  }

	return 0;
}
