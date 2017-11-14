#include <iostream>
#include <cstring>

using namespace std;

void print_dishes(int dishes[])
{
  for (int i=0; i < 40; i++)
  {
    if(dishes[i] == 0) cout << ' ';
    else if(dishes[i] == 1) cout << '.';
    else if(dishes[i] == 2) cout << 'x';
    else if(dishes[i] == 3) cout << 'W';
  }
  cout << endl;
}

int main ()
{
  int dna[10], old_dishes[40], new_dishes[40];
	int test_cases;
  string trash;
  cin >> test_cases, cin.ignore();
  while(test_cases--) {
    getline(cin, trash);
    for (int i = 0; i < 10; i++) cin >> dna[i];
    cin.ignore();
    for(int i=0; i < 40; i++) old_dishes[i] = 0;
    old_dishes[19] = 1;
    print_dishes(old_dishes);
    for(int i = 0; i < 49; i++) {
      for(int j = 0; j < 40; j++) {
        if(j==0) new_dishes[j] = dna[old_dishes[j] + old_dishes[j+1]];
        else if(j==39) new_dishes[j] = dna[old_dishes[j] + old_dishes[j-1]];
        else new_dishes[j] = dna[old_dishes[j] + old_dishes[j+1] + old_dishes[j-1]];
      }
      print_dishes(new_dishes);
      for(int j = 0; j < 40; j++) old_dishes[j] = new_dishes[j];
    }
    if(test_cases != 0) cout << endl;
  }
	return 0;
}
