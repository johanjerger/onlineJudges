#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	int round, asserts, mistakes;
  string response, guesses, result;
  set<char> response_set;
  vector<char> guesses_vec;

  while (cin >> round && round != -1) {
    cin >> response, cin.ignore();
    cin >> guesses, cin.ignore();
    for (int i = 0; i < response.size(); i++)
      response_set.insert(response[i]);
    asserts = mistakes = 0;
    for (auto& guess : guesses) {
      if (std::count(guesses_vec.begin(), guesses_vec.end(), guess) == 0) {
        if (response_set.count(guess) > 0) asserts++;
        else mistakes++;
        if (asserts == response_set.size()) break;
        guesses_vec.push_back(guess);
      }
    }
    if (asserts == response_set.size() && mistakes < 7) result = "You win.";
    if (mistakes > 6) result = "You lose.";
    if (mistakes < 7 && asserts < response_set.size()) result = "You chickened out.";
    cout << "Round " << round << endl << result << endl;
    response_set.clear(); guesses_vec.clear();
  }

	return 0;
}
