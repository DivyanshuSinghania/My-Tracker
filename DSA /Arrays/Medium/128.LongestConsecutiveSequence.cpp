#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int max = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            map[nums[i]] = 1;
        }
        
        for (int i = 0; i < n; i++)
        {
            if(map[nums[i]] == 2){
                continue;
            }
            map[nums[i]] += 1;
            int num1 = nums[i]+1;
            int num2 = nums[i]-1;
            int count = 1;
            // cout << max << endl;
            while(map.find(num1)!=map.end())
            {
                map[num1] += 1;
                count++;
                num1++;
            }
            if(max < count){
                max = count;
            }

            while(map.find(num2)!=map.end())
            {
                map[num2] += 1;
                map[nums[i]] += 1;
                count++;
                num2--;
            }
            if(max < count){
                max = count;
            }
            cout << "itr " << i+1 << " - max :" << max << " - num : " << nums[i] << endl;
        }
        return max;
    }
    

int main(){
    vector<int> nums;
    // [0,3,7,2,5,8,4,6,0,1] -> 9
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(7);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(8);
    nums.push_back(4);
    nums.push_back(6);
    nums.push_back(0);
    nums.push_back(1);
    // nums.push_back(-5);
    // nums.push_back(2);
    // nums.push_back(-4);

    longestConsecutive(nums);

    // cout << "Test Result: ";
    // // for (int num : longestConsecutive(nums)) cout << num << " ";
    // // for (int i = 0; i < nums.size(); i++)
    // // {
    // //     cout << nums[i]<<endl;
    // // }
    // // cout << endl;
    // cout << longestConsecutive(nums) << endl;
}