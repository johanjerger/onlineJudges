#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct dat {
  char concept;
  double num;
  char prefix;
  char unit;
};

int main ()
{
  int test_cases;
	string problem_def, aux, result;
  vector <dat> data;
  dat elem, result_str;
  cin >> test_cases, cin.ignore();
  for (int i = 1; i <= test_cases; i++) {
    getline(cin, problem_def);
    for (int j = 0; j < problem_def.size(); j++) {
      if (problem_def[j] == '=') {
        elem.concept = problem_def[j-1];
        aux = "";
        j++;
        while(isdigit(problem_def[j]) || problem_def[j] == '.' || problem_def[j] == '-')
          aux += problem_def[j++];
        elem.num = atof(aux.c_str());
        if (problem_def[j] == 'm' || problem_def[j] == 'k' || problem_def[j] == 'M')
          elem.prefix = problem_def[j++];
        else elem.prefix = '*';
        elem.unit = problem_def[j++];
        data.push_back(elem);
      }
    }

    if ((data[0].concept == 'P' && data[1].concept == 'U') || (data[0].concept == 'U' && data[1].concept == 'P')) {
      result_str.concept = 'I';
    } else if ((data[0].concept == 'P' && data[1].concept == 'I') || (data[0].concept == 'I' && data[1].concept == 'P')) {
      result_str.concept = 'U';
    } else {
      result_str.concept = 'P';
    }

    for (int i = 0; i < data.size(); i++) {
      if (data[i].prefix != '*') {
        if (data[i].prefix == 'M') data[i].num *= 1000000;
        if (data[i].prefix == 'k') data[i].num *= 1000;
        if (data[i].prefix == 'm') data[i].num *= 0.001;
      }
    }

    if (data[0].unit == 'V' && data[1].unit == 'W') {
      result_str.unit = 'A';
      result_str.num = data[1].num / data[0].num;
    } else if (data[0].unit == 'W' && data[1].unit == 'V') {
      result_str.unit = 'A';
      result_str.num = data[0].num / data[1].num;
    } else if (data[0].unit == 'A' && data[1].unit == 'W') {
      result_str.unit = 'V';
      result_str.num = data[1].num / data[0].num;
    } else if (data[0].unit == 'W' && data[1].unit == 'A') {
      result_str.unit = 'V';
      result_str.num = data[0].num / data[1].num;
    } else {
      result_str.unit = 'W';
      result_str.num = data[0].num * data[1].num;
    }

    cout << fixed << setprecision(2);
    cout << "Problem #" << i << endl << result_str.concept << "=" << result_str.num << result_str.unit << endl << endl;
    data.clear();
  }

	return 0;
}
