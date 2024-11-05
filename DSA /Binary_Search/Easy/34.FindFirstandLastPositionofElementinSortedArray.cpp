#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<=high)
        {
            int mid = high-(high-low)/2;
            if(nums[mid]<target){
                low = mid+1;
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else{
                // cout<<"hello"<<endl;
                int i = mid;
                int j = mid;
                while(i>-1 && nums[i]==target){
                    i--;
                }
                while(j<n && nums[j]==target){
                    j++;
                }
                ans[0] = i+1;
                ans[1] = j-1;
                return ans;
            }
        }
        return ans;
    }

int main(){
    int t = 2;
    vector<int> nums;
    // [5,7,7,8,8,10]
    // nums.push_back(5);
    // nums.push_back(7);
    // nums.push_back(7);
    // nums.push_back(8);
    // nums.push_back(8);
    // nums.push_back(9);
    nums.push_back(2);
    nums.push_back(2);
    // nums.push_back(-1);

    cout << "Test Result: ";
    for (int num : searchRange(nums, t)) cout << num << " ";
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout<<ans[i][j];
    //     }
    //     cout<< endl;
    // }
    // cout << endl;
    // cout << searchInsert(nums, 2) << endl;
}