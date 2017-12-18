#include <iostream>
#include<math.h>

using namespace std;

int main ()
{
    int test_cases, number, to, i;
    long long sum;
    cin >> test_cases;
    while(test_cases--) {
        cin >> number;
        sum = 0;
        for (i = 1; i*i < number; ++i)
            if (!(number % i)) sum += i + number / i;
        if (i * i == number) sum += i;
        sum -= number; // proper division
        cout << sum << endl;
    }
}
