// Here we are given a value V
// And an Infinite supply of {1,2,5,10,20,50,100,500,1000} -> (inputed) coins
// now we need to find min num of coins to reach V

// Eg. V = 30, coins = {20,15,5}

// Greedy algo sol, 20 - 1
//                  15 - 0
//                   5 - 2
// Ans - 3

// Optimal sol, 20 - 0
//              15 - 2
//               5 - 0
// Ans - 2


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int GreedyCoinChange(int amount, vector<int> coins){

    int collected_amount = 0;
    int no_coins = 0;

    sort(coins.begin(), coins.end());
    
    int i = coins.size()-1;

    while (i>=0)
    {
        if (coins[i]<=(amount-collected_amount) && collected_amount<amount)
        {
            cout << coins[i] << endl;
            no_coins++;
            collected_amount += coins[i];
            i++;
        }
        else if (collected_amount>amount)
        {
            no_coins--;
            collected_amount -= coins[i];
        }
        i--;
    }

    return no_coins;
}

int main() {
    vector<int> coins;

    int n = 0;
    cout << "Cash Amount" << endl;
    cin >> n;

    cout << "List the Coins Value: " << endl;
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        cin >> c;
        if(c==-1){
            break;
        }
        coins.push_back(c);
    }
    
    cout << GreedyCoinChange(n, coins) << endl;

    return 0;
}

