#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

void rev(vector<int>& nums, int m, int size){
        for (int i = 0; i < m/2; i++)
        {
            swap(nums[i], nums[m-i-1]);
        }
        for (int i = 0; i < size/2; i++)
        {
            swap(nums[i], nums[size-i-1]);
        }
        return;
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        rev(nums1, m, n+m);
        int k =0;
        for (int i = n, j=0; i <= m+n && j<n;)
        {
            if(i < n+m && nums1[i]<nums2[j]){
                nums1[k] = nums1[i];
                k++;
                i++;
            }
            else if(j < n){
                nums1[k] = nums2[j];
                k++;
                j++;
            }
        }
        return;
    }

int main(){
    int t = 0;
    vector<int> nums1;
    //  nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(0);
    nums1.push_back(0);
    nums1.push_back(0);

    vector<int> nums2;
    nums2.push_back(2);
    nums2.push_back(5);
    nums2.push_back(6);
    // nums.push_back(0);
    // nums.push_back(0);
    // nums.push_back(0);
    // nums.push_back(-1);
    // nums.push_back(-4);
    // nums.push_back(-5);
    // nums.push_back(2);
    // nums.push_back(-4);

    // vector<vector<int> > ans;
    merge(nums1, 3, nums2, 3);
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