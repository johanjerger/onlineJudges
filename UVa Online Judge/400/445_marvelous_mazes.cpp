#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  string maze_d, maze_row("");
  int repeat(0);
  while (getline(cin, maze_d)) {
    for (int i = 0; i < maze_d.size(); i++) {
      if (isdigit(maze_d[i]))
        repeat += maze_d[i] - '0';
      else if (isalpha(maze_d[i]) || maze_d[i] == '*') {
        if (maze_d[i] != 'b') cout << string(repeat, maze_d[i]);
        else cout << string(repeat, ' ');
        repeat = 0;
      } else if (maze_d[i] == '!') {
        cout << endl;
      }
    }
    cout << endl;
  }
}
