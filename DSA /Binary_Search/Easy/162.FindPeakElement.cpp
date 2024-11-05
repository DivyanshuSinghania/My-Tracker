#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = high - (high - low)/2;
            if (mid>0 && mid<n-1 && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
            {
                return mid;
            }
            else if (mid>0 && nums[mid]<nums[mid-1])
            {
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return high;
    }


int main(){
    int t = 2;
    vector<int> nums;
    // [4,5,6,7,0,1,2]
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(10);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(6);
    // nums.push_back(7);
    // nums.push_back(7);
    // nums.push_back(2);
    // nums.push_back(2);
    // nums.push_back(-1);

    cout << "Test Result: ";
    // for (int num : search(nums, t)) cout << num << " ";
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout<<ans[i][j];
    //     }
    //     cout<< endl;
    // }
    // cout << endl;
    cout << findPeakElement(nums) << endl;
}