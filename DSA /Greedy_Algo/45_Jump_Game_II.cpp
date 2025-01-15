#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int jump(vector<int>& nums) {
    int size = nums.size();
    int c = 0;
    int l = 0;
    int r = 0;
    
    int jumps = 0;

    int max = -1;
    while (r<size-1)
    {
        for (int i = l; i <= r; i++)
        {
            int temp = nums[i];
            if (nums[i]+i>max)
            {
                max = nums[i]+i;
            }
        }
        l = r+1;
        r = max;
        jumps++;
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