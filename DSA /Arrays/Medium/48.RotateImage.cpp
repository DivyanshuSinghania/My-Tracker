#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m/2; j++)
            {
                swap(matrix[i][j], matrix[i][m-j-1]);
            }
        }
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

    nextPermutation(nums);

    cout << "Test Result: ";
    // for (int num : nextPermutation(nums)) cout << num << " ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i]<<endl;
    }
    cout << endl;
    // cout << rearrangeArray(nums) << endl;
}