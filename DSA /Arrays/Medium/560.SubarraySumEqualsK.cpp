#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
    int subarraySum(vector<int>& nums, int k) {
        // int j = 0;
        unordered_map<int, int> map;
        int n = nums.size();
        int sum = 0;
        int count = 0;
        map[0] = 1;
        for (int i = 0; i < n;i++)
        {
            sum += nums[i];
            count += map[sum-k];
            map[sum] += 1;
        }
        return count;
    }

int main(){
    vector<int> nums;
    // nums = [1,2,3], k = 3 -> 2
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    // nums.push_back(-5);
    // nums.push_back(2);
    // nums.push_back(-4);
    int k = 3;
    // subarraySum(nums);

    cout << "Test Result: ";
    // for (int num : nextPermutation(nums)) cout << num << " ";
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << nums[i]<<endl;
    // }
    // cout << endl;
    cout << subarraySum(nums, k) << endl;
}