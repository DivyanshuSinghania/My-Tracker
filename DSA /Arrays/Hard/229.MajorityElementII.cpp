#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

// vector<int> majorityElement(vector<int>& nums) {
//         int count1 = 0 , count2 = 0;
//         int ele1 = INT_MIN;
//         int ele2 = INT_MIN;
//         for(int i=0 ; i < nums.size() ; i++){
//             if(count1 == 0 && nums[i] != ele2){
//                 count1 = 1;
//                 ele1 = nums[i];
//             }
//             else if(count2 == 0 && nums[i] != ele1){
//                 count2 = 1;
//                 ele2 = nums[i];
//             }
//             else if (ele1 == nums[i]) count1++;
//             else if (ele2 == nums[i]) count2++;
//             else{
//                 count1--;
//                 count2--;
//             }
//         }

//         int min = (int) (nums.size()/3) + 1;
//          count1 = 0 ; count2 = 0;
//         for(int i=0; i<nums.size() ; i++){
//             if (ele1 == nums[i]) count1++;
//             else if (ele2 == nums[i]) count2++;
//         }
//         vector<int> ls;
//         if(count1 >= min){
//             ls.push_back(ele1);
//         }
//         if(count2 >= min){
//             ls.push_back(ele2);
//         }

//         return ls;
//     }


    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return nums;
        }
        int num1 = INT_MIN;
        int cnt1 = 0;
        int num2 = INT_MIN;
        int cnt2 = 0;
    // [2,1,1,3,1,4,5,6]
        for (int i = 0; i < n; i++)
        {
            if(cnt1==0 && nums[i]!=num2){
                num1 = nums[i];
                cnt1=1;
            }
            else if(cnt2==0 && nums[i]!=num1){
                num2 = nums[i];
                cnt2=1;
            }
            else if(nums[i]==num1)cnt1++;
            else if(nums[i]==num2)cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if(nums[i]==num1)cnt1++;
            if(nums[i]==num2)cnt2++;
        }
        vector<int> ans;
        if (cnt1>int(n/3+1))
        {
            ans.push_back(num1);
        }
        if (cnt2>int(n/3+1) && num2!=num1)
        {   
            ans.push_back(num2);
        }
        return ans;
    }

    

int main(){
    vector<int> nums;
    // [1,3,3,2,2,4,3,3,5,5,6,3,3,7,7]
    // nums.push_back(1);
    // nums.push_back(3);
    // nums.push_back(3);
    // nums.push_back(2);
    // nums.push_back(2);
    // nums.push_back(4);
    // nums.push_back(3);
    // nums.push_back(3);
    // nums.push_back(5);
    // nums.push_back(5);
    // nums.push_back(6);
    // nums.push_back(3);
    // nums.push_back(3);
    // nums.push_back(7);
    // nums.push_back(7);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);

    // generate(nums);

    cout << "Test Result: ";
    for (int num : majorityElement(nums)) cout << num << " ";
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << nums[i]<<endl;
    // }
    // cout << endl;
    // // cout << rearrangeArray(nums) << endl;
}