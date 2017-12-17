#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

int main ()
{
        int test_cases, misil, size;
        string input;
        vector<int> sequence;

        cin >> test_cases, cin.ignore(), cin.ignore();
        while (test_cases--)
        {
                while (getline(cin, input) && !input.empty()) {
                        stringstream ss(input);
                        ss >> misil;
                        sequence.push_back(misil);
                }

                size = sequence.size();
                vector<int> lis(size, 1);
                vector<int> path(size, -1);
                lis[0] = 1;

                for (int i = 1; i < size; ++i)
                        for (int j = 0; j < i; ++j) {
                                int l = (sequence[j] < sequence[i]) ? lis[j] + 1 : 0;
                                if (l > lis[i]) lis[i] = l, path[i] = j;
                        }

                int i = distance(lis.begin(), max_element(lis.begin(), lis.end()));

                vector<int> print(1, sequence[i]);
                while (path[i] != -1) {
                        i = path[i];
                        print.insert(print.begin(), sequence[i]);
                }

                cout << "Max hits: " << print.size() << endl;
                copy(print.begin(), print.end(), ostream_iterator<int>(cout, "\n"));

                if (test_cases) cout << endl;
                sequence.clear();
        }
}
