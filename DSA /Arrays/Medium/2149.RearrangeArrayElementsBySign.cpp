#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n, 0);
        int pos = 0;
        int neg = 1;
        for (int i = 0; i<n; i++)
        {
            if(nums[i]>0){
                vec[pos] = nums[i];
                pos += 2;
            }
            else{
                vec[neg] = nums[i];
                neg += 2;
            }
        }
        return vec;
    }
    

int main(){
    vector<int> nums;
    // [3,1,-2,-5,2,-4]
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(-2);
    nums.push_back(-5);
    nums.push_back(2);
    nums.push_back(-4);
    cout << "Test Result: ";
    for (int num : rearrangeArray(nums)) cout << num << " ";
    cout << endl;

    // vector<int> nums = {1, -1, 2, -2, 3, -3};
    vector<int> vec;
    vec = rearrangeArray(nums);
    // cout << rearrangeArray(nums) << endl;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << nums[i]<<endl;
    // }
}