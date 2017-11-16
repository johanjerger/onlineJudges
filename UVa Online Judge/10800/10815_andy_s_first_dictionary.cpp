#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main ()
{
	set <string> dictionary;
  string str, word;
  while (getline(cin, str)) {
    word = "";
    for (int i=0; i < str.size(); i++) {
      if(isalpha(str[i])) word += tolower(str[i]);
      else if(!word.empty()) {
        dictionary.insert(word);
        word = "";
      }
    }
    if(!word.empty())
      dictionary.insert(word);
  }
  for(auto wrd : dictionary)
    cout << wrd << endl;

	return 0;
}
