#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
    // one pointer way(Kadane's Algorithm) - for SUM, need more for subsarray
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int start = 0;
        int end = 0;
        int max = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if(sum < 0){
                sum = 0;
                start = i;
            }
            sum += nums[i];
            if(sum>max)max=sum,end = i;
        }
       // start and end shows the substring index
       // return start, end, max;
       return max;
    }
    

int main(){
    vector<int> nums;
    // [-2,1,-3,4,-1,2,1,-5,4]
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    
    cout << maxSubArray(nums) << endl;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << nums[i]<<endl;
    // }
    
}