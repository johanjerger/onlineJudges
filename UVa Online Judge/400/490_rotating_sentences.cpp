#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  vector<string> inputs;
  string input;
  int max_input_size = 0;

  while (getline(cin, input) && !input.empty()) {
    inputs.push_back(input);
    max_input_size = max(max_input_size, (int)input.size());
  }

  for (int i = 0; i < max_input_size; i++) {
    for (int j = inputs.size() - 1; j > -1; j--)
      cout << ((i < inputs[j].size()) ? inputs[j][i] : ' ');
    cout << endl;
  }
}
