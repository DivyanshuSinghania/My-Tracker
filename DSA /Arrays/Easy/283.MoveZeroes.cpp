#include<iostream>
#include<vector>

using namespace std;

    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size();)
        {
            if(nums[i] == 0){
                i++;
            }
            else if(i != j){
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                i++, j++;
            }
            else{
                i++, j++;
            }
        }
        return;
    }

int main(){
    vector<int> nums;
    // 0,1,0,3,12
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(12);
    // nums.push_back(2);
    // nums.push_back(2);
    // nums.push_back(3);
    // nums.push_back(3);
    // nums.push_back(4);
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
    }
    
}