#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int banquetsToday(int past_days, vector<int>& bloomDay, int k, int size){
        int kSize = 0;
        int mToday = 0;
        for(int i = 0;i<size;i++)
        {
            // [1,10,2,9,3,8,4,7,5,6]
            if(bloomDay[i]<=past_days){
                kSize++;
                if(kSize == k){
                    mToday++;
                    kSize = 0;
                }
            }
            else{
                kSize = 0;
            }
        }
        return mToday;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long size = bloomDay.size();
        if(size < long(m)*long(k)){
            return -1;
        }
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int minm = INT_MAX;
        while (low<=high)
        {
            int mid = high - (high - low)/2;
            int mOnMid = banquetsToday(mid, bloomDay, k, size);
            if(mOnMid>m){
                high = mid-1;
                minm = min(minm, mid);
            }
            else if(mOnMid<m){
                low = mid+1;
            }
            else{
                high = mid-1;
                minm = min(minm, mid);
            }
        }
        // if (minm == INT_MAX)
        // {
        //     return high;
        // }
        return minm;
    }

int main(){

    int m = 4;
    int k = 2;
    vector<int> nums;
    // nums.push_back(1);
    // nums.push_back(10);
    // nums.push_back(3);
    // nums.push_back(10);
    // nums.push_back(2);
    // nums.push_back(7);
    // [1000000000,1000000000]
    // nums.push_back(1000000000);
    // nums.push_back(1000000000);
    // [1,10,2,9,3,8,4,7,5,6]
    nums.push_back(1);
    nums.push_back(10);
    nums.push_back(2);
    nums.push_back(9);
    nums.push_back(3);
    nums.push_back(8);
    nums.push_back(4);
    nums.push_back(7);
    nums.push_back(5);
    nums.push_back(6);

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
    cout << minDays(nums, m, k) << endl;
}