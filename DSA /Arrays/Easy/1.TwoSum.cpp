#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> map;
        for (int i = 0; i < n; i++)
        {
            if(map.find(target-nums[i]) != map.end()){
                vector<int> vec(2,-1);
                vec[0] = i;
                vec[1] = map[target-nums[i]];
                return vec;
            }
            else{
                map[nums[i]] = i;
            }
        }
        return nums;
    }

int main(){
    vector<int> nums;
    // [2,7,11,15]
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    nums = twoSum(nums, 9);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i]<<endl;
    }
    
}