// 5, 10, 20 -> available changes by people
// 5 -> cost of lemonade
// 0 -> starting change
// bills[] -> coutomer offer
// can i give every one?
// greedy algo

#include <iostream>
using namespace std;

bool lemonadeChange(vector<int> &bills){
    int change5=0;
    int change10=0;
    int change20=0;
    for (int i = 0; i < bills.size(); i++)
    {
        if (bills[i]==5)
        {
            change5++;
        }
        else if (bills[i]==10)
        {
            change5--;
            if (change5<0)
            {
                cout<<i<<endl;
                return false;
            }
            change10++;
        }
        else if (bills[i]==20)
        {
            if (change10==0)
            {
                change5--;
                change5--;
                change5--;
                if (change5<0)
                {
                    cout<<i<<endl;
                    return false;
                }
            }
            else
            {
                change10--;
                change5--;
                if (change5<0)
                {
                    // cout<< "change5: " << change5<< "change10: " << change10 << "change20: " << change20 << endl;
                    cout<<i<<endl;
                    return false;
                }
            }
            change20++;
        }
    }
    return true;
}


int main() {
    vector<int> coins;

    int n = 0;
    cout << "Number of costomers" << endl;
    cin >> n;

    cout << "List the Coustomer bills: " << endl;
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        cin >> c;
        if(c==-1){
            break;
        }
        coins.push_back(c);
    }
    
    cout << lemonadeChange(coins) << endl;

    return 0;
}
