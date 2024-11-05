#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        if(high == 1){
            if(nums[0] == target){
                return 0;
            }
            else if(nums[1] == target){
                return 1;
            }
            else{
                return -1;
            }
        }
        if(high == 0){
            if(nums[0] == target){
                return 0;
            }
            else{
                return -1;
            }
        }
        while(low<=high){

            int mid = (low+high)/2;

            if(nums[mid] == target){
                return mid;
            }

            else if(nums[mid] < target){
                if(nums[mid] < nums[high] && target > nums[high]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }

            else if(nums[mid] > target){
                if(nums[mid] >= nums[low] && target < nums[low]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }

// t = before break ,mid = before break -> both 1) nums[t]>nums[mid] -> low = mid + 1;
                                            //  2) nums[t]<nums[mid] -> high = mid - 1;
// t = before break ,mid = after break -> nums[t]>nums[low] -> nums[t]>nums[mid] -> high = mid - 1;
// t = after break ,mid = after break -> both 1) nums[t]>nums[mid] -> low = mid + 1;
                                          //  2) nums[t]<nums[mid] -> high = mid - 1;
// t = after break ,mid = before break -> nums[t]<nums[low] -> nums[t]<nums[mid] -> low = mid + 1;
// [5  6  7  8 break 1  2  3  4]


int main(){
    int t = 2;
    vector<int> nums;
    // [4,5,6,7,0,1,2]
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    // nums.push_back(2);
    // nums.push_back(2);
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
    cout << search(nums, 2) << endl;
}