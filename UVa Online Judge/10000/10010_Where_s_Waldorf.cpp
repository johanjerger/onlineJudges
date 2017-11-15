#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool can_find(const string word, vector<string> grid, int i, int j, int ltr, int iplus, int jplus)
{
  if(word[ltr] == grid[i][j]) ltr++;
  else return false;
  if(word.size() == ltr) return true;
  else if((i+iplus > -1 && i+iplus < grid.size()) && (j+jplus > -1 && j+jplus < grid[i+iplus].size()))
    return can_find(word, grid, i+iplus, j+jplus, ltr, iplus, jplus);
  else return false;
}

pair<int,int> find(const string word, vector<string> grid)
{
  for (int i=0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      if(grid[i][j] == word[0]) {
        if (word.size() == 1) return {i+1, j+1};
        if (grid.size() - i >= word.size()) {
          if ((i+1 < grid.size() && j+1 < grid[i+1].size()) && can_find(word, grid, i, j, 0, 1, 1)) return {i+1,j+1};
          else if ((i+1 < grid.size()) && can_find(word, grid, i, j, 0, 1, 0)) return {i+1,j+1};
          else if ((i+1 < grid.size() && j-1 > -1) && can_find(word, grid, i, j, 0, 1, -1)) return {i+1,j+1};
        }
        if ((j+1 < grid[i].size()) && can_find(word, grid, i, j, 0, 0, 1)) return {i+1,j+1};
        else if ((j-1 > -1) && can_find(word, grid, i, j, 0, 0, -1)) return {i+1,j+1};
        if (i+1 >= word.size()) {
          if ((i-1 > -1) && can_find(word, grid, i, j, 0, -1, 0)) return {i+1,j+1};
          else if ((i-1 > -1 && j+1 < grid[i-1].size()) && can_find(word, grid, i, j, 0, -1, 1)) return {i+1,j+1};
          else if ((i-1 > -1 && j-1 > -1) && can_find(word, grid, i, j, 0, -1, -1)) return {i+1,j+1};
        }
      }
    }
  }
}

int main ()
{
	int test_cases, rows, columns, word_count;
  string word;
  vector<string> grid;
  cin >> test_cases, cin.ignore();
  while (test_cases--) {
    cin.ignore();
    cin >> rows >> columns, cin.ignore();
    while(rows--) {
      cin >> word, cin.ignore();
      std::transform(word.begin(), word.end(), word.begin(), ::tolower);
      grid.push_back(word);
    }
    cin >> word_count, cin.ignore();
    while (word_count--) {
      getline(cin, word);
      std::transform(word.begin(), word.end(), word.begin(), ::tolower);
      pair<int,int> res = find(word, grid);
      cout << res.first << ' ' << res.second << endl;
    }
    if (test_cases != 0) cout << endl;
    grid.clear();
  }

	return 0;
}
