#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(vector<int>& nums) {
    int size = nums.size();
    int jumpNode = size-1;

    int i = size-2;
    while (i >= 0)
    {
        if (nums[i]>=jumpNode-i)
        {
            jumpNode = i;
        }
        i--;
    }
    // if (jumpNode == 0)
    // {
    //     return true;
    // }
    // return false;
    return jumpNode==0;
}

int main() {

    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(4);

    cout << canJump(nums) << endl;
    return 0;
}