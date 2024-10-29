#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;


    vector<vector<int> > threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int low = i+1;
            int high = n-1;
            int val = -nums[i];
            while(low<high){
                if(nums[low]+nums[high]>val){
                    high--;
                }
                else if(nums[low]+nums[high]<val){
                    low++;
                }
                else{
                    vector<int> vec;
                    vec.push_back(nums[low]);
                    vec.push_back(nums[high]);
                    vec.push_back(-val);
                    ans.push_back(vec);
                    low++;
                    while(nums[low]==nums[low-1] && low<high){
                        low++;
                    }
                }
            }
        }
        return ans;
    }
    

int main(){
    vector<int> nums;
    // nums = [-1,0,1,2,-1,-4]
    // nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    // nums.push_back(-1);
    // nums.push_back(-4);
    // nums.push_back(-5);
    // nums.push_back(2);
    // nums.push_back(-4);

    vector<vector<int> > ans;
    ans = threeSum(nums);

    cout << "Test Result: ";
    // for (int num : threeSum(nums)) cout << num << " ";
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j];
        }
        cout<< endl;
    }
    cout << endl;
    // cout << rearrangeArray(nums) << endl;
}