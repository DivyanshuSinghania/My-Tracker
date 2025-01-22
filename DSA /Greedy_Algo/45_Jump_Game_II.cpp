#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int jump(vector<int>& nums) {
    int size = nums.size();
    int jumps = 0;
    int max_jump_length = nums[0];

    int temp = 0;
    int temp1 = 0;
    while(max_jump_length<size){
        // cout << max_jump_length << endl;
        if (max_jump_length==size-1)
        {
            jumps++;
            return jumps;
        }
        
        temp = max_jump_length;
        for (int i = temp1; i < max_jump_length; i++)
        {
            // cout << "in" << endl;
            if (nums[i]+i>max_jump_length)
            {
                max_jump_length = nums[i]+i;
                jumps ++;
            }
        }
        temp1 = temp;
    }

    return jumps;
}

int main() {

    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);

    int res = jump(nums);
    cout << res << endl;
    return 0;
}