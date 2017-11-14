#include <iostream>

using namespace std;

int calculate_terms(long long int num, long long int limit)
{
  if (num > limit) return 0;
  if (num == 1) return 1;
  if (num % 2 == 0) return calculate_terms(num/2, limit) + 1;
  if (((num+1) % 2) == 0) return calculate_terms((3*num)+1, limit) + 1;
}

int main ()
{
	long long int num, limit, case_number = 0;
  while (cin >> num >> limit && num > -1 && limit > -1)
    cout <<  "Case " << ++case_number << ": A = " << num << ", limit = "
      << limit << ", number of terms = " << calculate_terms(num, limit) << endl;
}
