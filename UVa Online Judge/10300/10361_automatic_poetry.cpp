#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
	int test_cases;
  string line1, line1_trimed, line2, aux;
  vector <string> words;
  cin >> test_cases, cin.ignore();
  while (test_cases--) {
      int pos = 0; char delim = '<';
      getline(cin, line1);
      aux = line1_trimed = "";
      for (; pos < line1.size(); pos++) {
        if (line1[pos] != delim) {
          line1_trimed += line1[pos];
          aux += line1[pos];
        } else {
          delim = (delim == '<') ? '>' : '<';
          words.push_back(aux);
          aux = "";
        }
      }
      words.push_back(aux);
      getline(cin, line2);
      line2.erase(line2.size()-3, 3);
      line2 += words[3] + words[2] + words[1] + words[4];
      cout << line1_trimed << endl << line2 << endl;
      words.clear();
  }

	return 0;
}
