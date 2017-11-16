#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int rules;
  vector <string> find;
  vector <string> replace;
  string find_word, replace_word, text;
  while (cin >> rules && rules != 0) {
    cin.ignore();
    while (rules--) {
      getline(cin, find_word); getline(cin, replace_word);
      find.push_back(find_word);
      replace.push_back(replace_word);
    }
    getline(cin, text);
    for (int i=0; i < find.size(); i++) {
      if (text.find(find[i]) == string::npos) continue;
      text.replace(text.find(find[i]), find[i].length(), replace[i]);
      --i;
    }
    cout << text << endl;
    find.clear();
    replace.clear();
  }
	return 0;
}
