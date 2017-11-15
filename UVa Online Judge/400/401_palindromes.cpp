#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main ()
{
	map<char, char> valids = {{'A', 'A'}, {'B', '*'}, {'C', '*'}, {'D', '*'}, {'E', '3'}, {'F', '*'}, {'G', '*'}, {'H', 'H'}, {'I', 'I'}, {'J', 'L'}, {'K', '*'}, {'L', 'J'}, {'M', 'M'}, {'N', '*'}, {'O', 'O'}, {'P', '*'}, {'Q', '*'}, {'R', '*'}, {'S', '2'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'}, {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'}, {'1', '1'}, {'2', 'S'}, {'3', 'E'}, {'4', '*'}, {'5', 'Z'}, {'6', '*'}, {7, '*'}, {'8', '8'}, {'9', '*'}};
  string word, reverse_word, result;
  bool is_pal, is_mir;
  while(getline(cin, word)) {
    is_pal = is_mir = true;
    reverse_word = word;
    reverse(reverse_word.begin(), reverse_word.end());
    is_pal = word == reverse_word;
    for (int i = 0; i < word.size(); i++)
      is_mir &= (valids.at(word[i]) == word[word.size()-(i+1)]);
    if(is_pal && is_mir) result = " -- is a mirrored palindrome.";
    else if (is_pal) result = " -- is a regular palindrome.";
    else if (is_mir) result = " -- is a mirrored string.";
    else result = " -- is not a palindrome.";
    cout << word << result << endl << endl;
  }
  return 0;
}
