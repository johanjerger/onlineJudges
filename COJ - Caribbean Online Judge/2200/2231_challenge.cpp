#include <iostream>

using namespace std;

int main()
{
  int rounds, a = 0, b = 0;
  string a_play, b_play, result = "tied";

  cin >> rounds, cin.ignore();
  while (rounds--) {
    cin >> a_play >> b_play, cin.ignore();

    if (a_play == "paper" && b_play == "rock") a++;
    else if (a_play == "rock" && b_play == "scissors") a++;
    else if (a_play == "scissors" && b_play == "paper") a++;
    else if (a_play == "rock" && b_play == "paper") b++;
    else if (a_play == "scissors" && b_play == "rock") b++;
    else if (a_play == "paper" && b_play == "scissors") b++;
  }

  if (a > b) result = "A win";
  else if (b > a) result = "B win";
  cout << result << endl;

  return 0;
}
