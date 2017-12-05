#include <iostream>

using namespace std;

int LD[2005][2005];

int ld(string s1, string s2, int size1, int size2)
{
    for (int j = 0; j <= size1; j++) LD[0][j] = j;
    for (int i = 0; i <= size2; i++) LD[i][0] = i;

    for (int i = 1; i <= size2; i++)
      for (int j = 1; j <= size1; j++)
        LD[i][j] = min(min(LD [i-1][j-1] + (s1[j-1] != s2[i-1]), LD[i-1][j] + 1), LD[i][j-1] + 1);

    return LD[size2][size1];
}

int main ()
{
  int size1, size2;
  string str1, str2;
  while (cin >> size1 >> str1 >> size2 >> str2)
    cout << ld(str1, str2, size1, size2) << endl;
}
