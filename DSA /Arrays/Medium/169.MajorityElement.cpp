#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if(count == 0){
                num = nums[i];
            }
            if (nums[i]==num)
            {
                count++;
            }
            else{
                count--;
            }    
        }
        return num;
    }
    

int main(){
    vector<int> nums;
    // [2,2,1,1,1,2,2]
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    
    cout << majorityElement(nums) << endl;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << nums[i]<<endl;
    // }
    
}