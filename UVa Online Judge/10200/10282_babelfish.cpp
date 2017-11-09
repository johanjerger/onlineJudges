#include <iostream>
#include <sstream>
#include <map>

using namespace std;

int main()
{
  string input, native_word, foreign_word, translation;
  map<string, string> dictionary;

  while (getline(cin, input) && !input.empty()) {
    stringstream ss(input.c_str());
    ss >> native_word >> foreign_word;
    dictionary.insert({foreign_word, native_word});
  }

  while (getline(cin, foreign_word) && !foreign_word.empty()) {
    if (dictionary.count(foreign_word) == 0) translation = "eh";
    else translation = dictionary.at(foreign_word);
    cout << translation << endl;
  }
}
