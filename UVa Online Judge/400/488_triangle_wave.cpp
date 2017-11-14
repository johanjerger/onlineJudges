#include <iostream>

using namespace std;

int main ()
{
	int test_cases, amplitude, frequency;
	string trash;
	cin >> test_cases, cin.ignore();
	while (test_cases--) {
		getline(cin, trash);
		cin >> amplitude, cin.ignore();
		cin >> frequency, cin.ignore();
		while (frequency--) {
			for (int i = 1; i <= amplitude; i++)
				cout << string(i, i + '0') << endl;
			for (int i = amplitude - 1; i > 0; i--)
				cout << string(i, i + '0') << endl;
			if(frequency != 0 || test_cases != 0) cout << endl;
		}
	}

	return 0;
}
