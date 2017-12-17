#include <iostream>
#include <vector>

using namespace std;

int lis(vector<int> sequence)
{
        int maximum = -1, size = sequence.size();
        vector<int> lis(size, 0);

        for (int i = 0; i < size; i++) {
                lis[i] = 1;
                for (int j = 0; j < i; j++)
                        if (sequence[j] < sequence[i] && lis[j] + 1 > lis[i])
                                lis[i] = lis[j] + 1;
                maximum = max(lis[i], maximum);
        }

        return maximum;
}

int main()
{
        int size, value;
        vector<int> sequence;
        cin >> size;
        for (int i = 0; i < size; i++) {
                cin >> value;
                sequence.push_back(value);
        }
        cout << lis(sequence) << endl;
}
