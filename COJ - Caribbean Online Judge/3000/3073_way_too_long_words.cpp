#include <iostream>

using namespace std;

int main()
{
  int words_count, word_size;
  string word;

  cin >> words_count, cin.ignore();
  while (words_count--) {
    cin >> word;
    word_size = word.length();
    if (word_size > 10)
      word = word.front() + to_string(word_size - 2) + word.back();
    cout << word << endl;
  }
  return 0;
}
