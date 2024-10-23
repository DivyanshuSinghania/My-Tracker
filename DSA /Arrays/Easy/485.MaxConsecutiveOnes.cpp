#include<iostream>
#include<vector>

using namespace std;

    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current = 0;
        int max = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1){
                current++;
            }
            else{
                if(max < current){
                    max = current;
                }
                current = 0;
            }
        }
        if(max < current){
            max = current;
        }
        return max;
    }

int main(){
    vector<int> nums;
    // [1,1,0,1,1,1]
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(2);
    // nums.push_back(3);
    // nums.push_back(3);
    // nums.push_back(4);
    cout << findMaxConsecutiveOnes(nums) << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
    }
    
}