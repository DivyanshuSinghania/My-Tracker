#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int twos = n-1;
        for (int i = 0; i<=twos;)
        {
            if(nums[i]==0){
                swap(nums[i], nums[zero]);
            }
            if(nums[i]==2){
                swap(nums[i], nums[twos]);
            }
            while(zero<n-1&&nums[zero+1]==0)zero++;
            i = zero+1;
            while(twos>0&&nums[twos]==2)twos--;
        }
    }

int main(){
    vector<int> nums;
    // [2,0,2,1,1,0]
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(0);
    // nums.push_back(2);
    // nums.push_back(1);
    // nums.push_back(0);
    sortColors(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i]<<endl;
    }
    
}