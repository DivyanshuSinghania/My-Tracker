#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int num = prices[0];
        int max = INT_MIN;
        int profit = 0;
        for (int i = 0; i < n; i++)
        {
            profit = prices[i] - num;
            if(profit < 0){
                profit = 0;
                num = prices[i];
            }
            if(profit>max){
                max = profit;
            }
        }
        return max;
    }

int main(){
    vector<int> nums;
    // [7,1,5,3,6,4]
    nums.push_back(7);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(4);
    // nums.push_back(0);
    cout << maxProfit(nums) << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    
}