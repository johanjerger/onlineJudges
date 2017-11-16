#include <iostream>
#include <vector>

using namespace std;

string erase_zeros (string str)
{
  for (int i = 0; i < str.size(); i++) {
    if (str[i] != '0') break;
    str.erase(0,1);
    i--;
  }
  return (str.empty()) ? "0" : str;
}

string bigsum(string number1, string number2)
{
  string result = number1;
  int res, rest;

  if(result.size() > number2.size())
    number2 = string(result.size() - number2.size(), '0') + number2;
  else result = string(number2.size() - result.size(), '0') + result;
  rest = res = 0;
  for (int j = result.size() - 1; j >= 0; j--) {
    res = (result[j] - '0') + (number2[j] - '0') + rest;
    if (res > 9) {
      rest = 1;
      res -= 10;
    } else {
      rest = 0;
    }
    result.replace(j, 1, to_string(res));
  }
  if (rest == 1) result = "1" + result;
  return erase_zeros(result);
}

string bigmultisum(vector<string> numbers)
{
  string result = numbers[0];
  for (int i=1; i < numbers.size(); i++) {
    result = bigsum(result, numbers[i]);
  }
  return erase_zeros(result);
}

string bigmult(string num, string mult)
{
  string mult_result = "";
  vector<string> numbers;
  int res, rest;
  for (int i=mult.size()-1; i >= 0; i--) {
    rest = res = 0;
    for (int j = num.size()-1; j >=0; j--) {
      res = ((mult[i] - '0') * (num[j] - '0')) + rest;
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
  return bigmultisum(numbers);
}

int main ()
{
	string number1, symbol, number2, result;
  string intmax = "2147483647";
  while (cin >> number1 >> symbol >> number2) {
    if(symbol == "+")
      result = bigsum(number1, number2);
    else
      result = bigmult(number1, number2);

    cout << number1 << ' ' << symbol << ' ' << number2 << endl;

    number1 = erase_zeros(number1);
    number2 = erase_zeros(number2);

    if (number1.size() > intmax.size())
      cout << "first number too big" << endl;
    else if (number1.size() == intmax.size() && number1 > intmax)
      cout << "first number too big" << endl;

    if (number2.size() > intmax.size())
      cout << "second number too big" << endl;
    else if (number2.size() == intmax.size() && number2 > intmax)
      cout << "second number too big" << endl;

    if (result.size() > intmax.size())
      cout << "result too big" << endl;
    else if (result.size() == intmax.size() && result > intmax)
      cout << "result too big" << endl;

  }
	return 0;
}
