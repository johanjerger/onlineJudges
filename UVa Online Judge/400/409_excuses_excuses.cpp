#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main ()
{
	set <string> excuses;
  vector <string> worst_excuses;
  string excuse, frase, aux_frase, word;
  int excuses_number, frase_number, max, num, set_id = 0;
  while (cin >> excuses_number >> frase_number) {
    cin.ignore();
    max = 0;
    while (excuses_number--) {
      getline(cin, excuse);
      excuses.insert(excuse);
    }
    while (frase_number--) {
      num = 0;
      getline(cin, frase);
      worst_excuses.push_back(frase);
      aux_frase = frase;
      std::transform(aux_frase.begin(), aux_frase.end(), aux_frase.begin(), ::tolower);
      word = "";
      for(int i = 0; i < aux_frase.size(); i++) {
        if (isalpha(aux_frase[i]))
          word += aux_frase[i];
        else if (excuses.find(word) != excuses.end()) {
          num++;
          word = "";
        } else {
          word = "";
        }
      }
      if (excuses.find(word) != excuses.end()) {
        num++;
        word = "";
      }
      if (worst_excuses.size() > 1) {
        if (num < max)
          worst_excuses.pop_back();
        else if (num > max) {
          worst_excuses.clear();
          worst_excuses.push_back(frase);
          max = num;
        }
      } else max = num;
    }
    cout << "Excuse Set #" << ++set_id << endl;
    for (int i = 0; i < worst_excuses.size(); i++)
      cout << worst_excuses[i] << endl;
    cout << endl;
    excuses.clear();
    worst_excuses.clear();
  }

	return 0;
}
