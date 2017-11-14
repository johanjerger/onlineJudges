#include <iostream>
#include <sstream>

using namespace std;

int main ()
{
  int count;
  bool is_word;
  string str, word;

  while (getline(cin, str)) {
    count = 0;
    stringstream ss(str.c_str());
    while (ss >> word) {
      is_word = false;
      for (int i = 0; i < word.size(); i++)
        if(isalpha(word[i])) {
          if(!is_word) count++;
          is_word = true;
        } else is_word = false;
    }
    cout << count << endl;
  }

  return 0;
}
