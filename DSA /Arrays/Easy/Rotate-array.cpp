#include<iostream>
#include<vector>

using namespace std;


    void rotated(vector<int>& nums, int k) {
        int n;
        for (int i = 0, j = nums.size()-k-1; i <= j; i++, j--)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        for (int i = nums.size()-k, j = nums.size()-1; i <= j; i++, j--)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        for (int i = 0, j = nums.size()-1; i <= j; i++, j--)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        return;
    }

int main(){
    vector<int> nums;
    // 1,2,3,4,5,6,7
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    // nums.push_back(3);
    // nums.push_back(3);
    // nums.push_back(4);
    int k = 3;
    // cout << rotated(nums, k) << endl;
    rotated(nums, k);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
    }
    
}