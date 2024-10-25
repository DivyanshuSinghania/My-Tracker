#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
 
  int n = mat.size();
  int m = mat[0].size();
  
  
  int top = 0, left = 0, bottom = n - 1, right = m - 1;

  
  while (top <= bottom && left <= right) {
      
  
    for (int i = left; i <= right; i++)
      ans.push_back(mat[top][i]);

    top++;

  
    for (int i = top; i <= bottom; i++)
      ans.push_back(mat[i][right]);

    right--;
    
    
    if (top <= bottom) {
      for (int i = right; i >= left; i--)
       ans.push_back(mat[bottom][i]);

      bottom--;
    }

    
    if (left <= right) {
      for (int i = bottom; i >= top; i--)
        ans.push_back(mat[i][left]);

      left++;
    }
  }
  return ans;
    }

int main(){
    vector<int> nums;
    // [1,2,3] -> [1,3,2]
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    // nums.push_back(-5);
    // nums.push_back(2);
    // nums.push_back(-4);

    spiralOrder(nums);

    cout << "Test Result: ";
    // for (int num : nextPermutation(nums)) cout << num << " ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i]<<endl;
    }
    cout << endl;
    // cout << rearrangeArray(nums) << endl;
}