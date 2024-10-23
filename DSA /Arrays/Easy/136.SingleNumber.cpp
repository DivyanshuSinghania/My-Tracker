#include<iostream>
#include<vector>

using namespace std;

    int singleNumber(vector<int>& nums) {
        int num = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            num = num ^ nums[i];
        }
        return num;
    }

int main(){
    vector<int> nums;
    // [4,1,2,1,2]
    nums.push_back(4);
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(1);
    // nums.push_back(2);
    cout << singleNumber(nums) << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
    }
    
}