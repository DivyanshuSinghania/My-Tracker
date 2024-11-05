#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int maxProduct(vector<int>& nums) {

        int n = nums.size();
        int prod = 1;
        int prodmax = INT_MIN;
        for (int j = 0;j<n; j++)
        {
            if(j<n-1 && nums[j]==0 && nums[j+1]==0){
                continue;
            }
            if(prod==0){
                prodmax = max(prodmax, prod);
                prod = 1;
            }
            prod = prod*nums[j];
            prodmax = max(prodmax, prod);
        }
        prod = 1;
        for (int j = n-1;j>=0; j--)
        {
            if(j>0 && nums[j]==0 && nums[j-1]==0){
                continue;
            }
            if(prod==0){
                prodmax = max(prodmax, prod);
                prod = 1;
            }
            prod = prod*nums[j];
            prodmax = max(prodmax, prod);
        }
        return prodmax;
    }

int main(){
    int t = 0;
    vector<int> nums;
    // [2,3,-2,4]
    // nums.push_back(0);
    // nums.push_back(0);
    // nums.push_back(-2);
    // nums.push_back(0);
    // nums.push_back();
    nums.push_back(0);
    nums.push_back(-1);
    // nums.push_back(0);
    // nums.push_back(-2);
    // nums.push_back(-1);
    // nums.push_back(-1);
    // nums.push_back(-1);
    // nums.push_back(-1);
    // nums.push_back(-1);
    // nums.push_back(-1);
    // nums.push_back(-1);
    // nums.push_back(-1);
    // nums.push_back(-2);
    // nums.push_back(0);
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(9);
    // nums.push_back(-1);
    // nums.push_back(4);
    // nums.push_back(2);
    // nums.push_back(3);
    // nums.push_back(-2);
    // nums.push_back(4);
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(2);
    // nums.push_back(0);
    // nums.push_back(0);
    // nums.push_back(0);
    // nums.push_back(0);
    // nums.push_back(0);
    // nums.push_back(-1);
    // nums.push_back(-4);
    // nums.push_back(-5);
    // nums.push_back(2);
    // nums.push_back(-4);

    cout << "Test Result: ";
    // for (int num : threeSum(nums)) cout << num << " ";
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout<<ans[i][j];
    //     }
    //     cout<< endl;
    // }
    // cout << endl;
    cout << maxProduct(nums) << endl;
}