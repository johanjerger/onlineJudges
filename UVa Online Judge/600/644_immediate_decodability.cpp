#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main ()
{
  string code, result;
  vector <string> codes;
	int set_num = 0;
  bool is_imm = true;
  while (cin >> code) {
    if (code == "9") {
      result = (is_imm) ? "is immediately decodable" : "is not immediately decodable";
      cout << "Set " << ++set_num << " " << result << endl;
      is_imm = true;
      codes.clear();
      continue;
    }
    if (!is_imm) continue;
    if (codes.empty()) { codes.push_back(code); continue;}
    for (int i = 0; i < codes.size(); i++) {
      if (code > codes[i])
        is_imm = is_imm && !(code.rfind(codes[i], 0) == 0);
      else
        is_imm = is_imm && !(codes[i].rfind(code, 0) == 0);
    }
    codes.push_back(code);
  }
	return 0;
}
