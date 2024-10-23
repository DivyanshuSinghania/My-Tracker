#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        for (int i = n-1; i > 0; i--)
        {
            if(nums[i]>nums[i-1]){
                // Swap i-1 with the element just bigger from it from the back of array
                for (int k = n-1; k >= i; k--)
                {
                    if(nums[k]>nums[i-1]){
                        swap(nums[k], nums[i-1]);
                        // Reverse the remaining array
                        for (int j = n-1; i < j; i++, j--)
                        {
                            swap(nums[i], nums[j]);
                        }
                        return;
                    }
                }
            }
        }
        for (int i = 0, j = n-1; i < j; i++, j--)
        {
            swap(nums[i], nums[j]);
        }
        return;
    }
    

int main(){
    vector<int> nums;
    // [1,2,3] -> [1,3,2]
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    // nums.push_back(-5);
    // nums.push_back(2);
    // nums.push_back(-4);

    nextPermutation(nums);

    cout << "Test Result: ";
    // for (int num : nextPermutation(nums)) cout << num << " ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i]<<endl;
    }
    cout << endl;
    // cout << rearrangeArray(nums) << endl;
}