#include <iostream>

using namespace std;

int LCS[1005][1005];

int lcs(string str1, string str2)
{
        int size1 = str1.size(), size2 = str2.size();

        for (int i = 0; i <= size1; i++) LCS[0][i] = 0;
        for (int i = 0; i <= size2; i++) LCS[i][0] = 0;

        for(int i = 1; i <= size1; i++)
                for(int j = 1; j <= size2; j++)
                        if(str1[i-1] == str2[j-1]) LCS[i][j] = LCS[i-1][j-1]+1;
                        else LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);

        return LCS[size1][size2];
}

int main ()
{
        string str1, str2;
        while (getline(cin, str1)) {
                getline(cin, str2);
                cout << lcs(str1, str2) << endl;
        }
}
