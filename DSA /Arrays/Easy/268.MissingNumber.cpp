#include<iostream>
#include<vector>

using namespace std;

    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int num = n*(n+1)/2;
        for (int i = 0; i < n; i++)
        {
            num -= nums[i];
        }
        return num;
    }

int main(){
    vector<int> nums;
    // [9,6,4,2,3,5,7,0,1]
    // nums.push_back(0);
    nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(3);
    // nums.push_back(4);
    // nums.push_back(5);
    // nums.push_back(6);
    // nums.push_back(7);
    // nums.push_back(8);
    // nums.push_back(9);
    cout << missingNumber(nums) << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
    }
    
}