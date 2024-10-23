#include<iostream>
#include<vector>

using namespace std;


    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        int count = 0;
        for (int i = 0, j = 0; i < nums.size();)
        {
            if(nums[i] < nums[i+1]){
                i++;
                j++;
                nums[j] = nums[i];
            }
            else{
                count++;
                i++;
            }
        }
        return --count;
    }

int main(){
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    cout << removeDuplicates(nums) << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
    }
    
}