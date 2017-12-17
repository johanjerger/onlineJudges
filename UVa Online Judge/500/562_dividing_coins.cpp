#include <iostream>
#include <vector>

using namespace std;

int ks[25005];
vector<int> coins;

int knapsack(int total_coins, int weigth_limit){
        for(int i = 0; i <= weigth_limit; i++) ks[i] = 0;

        for(int i = 0; i< total_coins; i++)
                for(int j = weigth_limit; j > 0; j--)
                        if(coins[i] <= j) ks[j] = max(ks[j], coins[i] + ks[j - coins[i]]);

        return ks[weigth_limit];
}

int main()
{
        int test_cases, total_coins, value, sum;
        cin >> test_cases;
        while(test_cases--) {
                cin >> total_coins;
                sum = 0;
                for (int i = 0; i < total_coins; i++) {
                        cin >> value;
                        coins.push_back(value);
                        sum += value;
                }
                cout << sum - 2 * knapsack(total_coins, sum/2) << endl;
                coins.clear();
        }
}
