#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = high - (high - low)/2;
            // cout << "mid " << mid << endl;
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += (nums[i] + mid - 1)/mid;
            }
            // cout << "sum " << sum << endl;
            // cout << endl;
            if(sum > threshold){
                low = mid+1;
            }
            else if(sum <= threshold){
                high = mid-1;
                ans = min(ans, mid);
            }
        }
        return ans;
    }

int main(){

    // int k = 2;
    vector<int> nums;
// nums = [44,22,33,11,1], threshold = 5
    int t = 5;
    nums.push_back(44);
    nums.push_back(22);
    nums.push_back(33);
    nums.push_back(11);
    nums.push_back(1);
    // nums.push_back(8);

    cout << "Test Result: " << endl;
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
    cout << smallestDivisor(nums, t) << endl;
}