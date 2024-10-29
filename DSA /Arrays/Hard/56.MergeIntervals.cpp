#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        int size = 0;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<=ans[size][1]){
                if(ans[size][1]<intervals[i][1]) ans[size][1] = intervals[i][1];
            }
            else{
                ans.push_back(intervals[i]);
                size++;
            }
        }
        return ans;
    }

int main(){
    int t = 0;
    vector<int> nums;
    // [-2,-1,-1,1,1,2,2]
    nums.push_back(-2);
    nums.push_back(-1);
    nums.push_back(-1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    // nums.push_back(0);
    // nums.push_back(0);
    // nums.push_back(0);
    // nums.push_back(0);
    // nums.push_back(0);
    // nums.push_back(-1);
    // nums.push_back(-4);
    // nums.push_back(-5);
    // nums.push_back(2);
    // nums.push_back(-4);

    vector<vector<int> > ans;
    ans = merge(nums, t);

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