#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while (low<=high)
        {
            int mid = high - (high - low)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }

int main(){
    int t = 0;
    vector<int> nums;
    // [-1,0,3,5,9,12]
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(9);
    nums.push_back(12);
    // nums.push_back(-1);

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
    cout << search(nums, 2) << endl;
}