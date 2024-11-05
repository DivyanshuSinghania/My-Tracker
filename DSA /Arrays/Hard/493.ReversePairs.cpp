#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int cntRP(vector<int>& nums, int low, int mid, int high){
        int cnt =0;
        if(low>=high){
            return 0;
        }
        
        
        


        return cntRP(nums, low, high/2) + cntRP(nums, high/2+1, high);
    }

    void merge(vector<int>& nums) {

    }

int main(){
    int t = 0;
    vector<int> nums1;
    // [2,4,3,5,1]
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(0);
    nums1.push_back(0);
    nums1.push_back(0);

    // vector<vector<int> > ans;
    merge(nums1);
    // nums1 = rev(nums1, 3, 6);

    cout << "Test Result: ";
    // for (int num : threeSum(nums)) cout << num << " ";
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;
    // cout << rearrangeArray(nums) << endl;
}