#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

    long OneTraverse(vector<int> piles, int k){
        int n = piles.size();
        long count = 0;
        for (int i = 0; i < n; i++)
        {
            count = 2*count - (count - (2*piles[i]-(piles[i]-k)-1)/k);
        }
        if(count>1000000000){
            return 1000000001;
        }
        return count;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int mink = INT_MAX;
        int low = 0;
        int high = *max_element(piles.begin(), piles.end());
        while(low<=high){
            int mid = high - (high - low)/2;
            if(mid < 1){
                return mid;
            }
            int h_check = OneTraverse(piles, mid);
            // cout<<high<<endl;
            // cout<<mid<<endl;
            // cout<<h_check<<endl;
            if(h_check>h){
                low = mid+1;
            }
            else if(h_check<h){
                mink = min(mink, mid);
                high = mid-1;
            }
            else{
                mink = min(mink, mid);
                high = mid-1;
            }
        }
        return mink;
    }

int main(){
    // Example 1:
    // Input: piles = [3,6,7,11], h = 8
    // Output: 4

    // Example 2:
    // Input: piles = [30,11,23,4,20], h = 5
    // Output: 30

    // Example 3:
    // Input: piles = [30,11,23,4,20], h = 6
    // Output: 23

    // Example 3:
    // Input: piles = [805306368,805306368,805306368], h = 1000000000
    // Output: ??

    int h = 2;
    vector<int> nums;
    // nums.push_back(3);
    // nums.push_back(6);
    // nums.push_back(7);
    // nums.push_back(11);
    // nums.push_back(7);
    // nums.push_back(7);
    nums.push_back(2);
    nums.push_back(2);
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
    cout << minEatingSpeed(nums, h) << endl;
}