#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;


    vector<vector<int>> generate(int n) {
        vector<int> v(n);
    vector<int> v1;
    vector<vector<int> > v2(n);
    int a = 1;

    v[0] = 1;
    v2[0].emplace_back(1);

    for (int i = 2; i < n + 1; i++)
    {
        int k = 1;
        v1 = v;
        while (k < i)
        {
            v[k] = v[k] + v1[k - 1];
            k++;
        }

        for (int j = 0; j < n; j++)
        {
            if (v[j] != 0)
            {
                v2[a].emplace_back(v[j]);
            }
        }
        a++;

        cout << endl;
    }
    return v2;
    }

    

int main(){
    // vector<int> nums;
    // // [1,2,3] -> [1,3,2]
    // nums.push_back(3);
    // nums.push_back(2);
    // nums.push_back(1);
    // // nums.push_back(-5);
    // // nums.push_back(2);
    // // nums.push_back(-4);

    // generate(nums);

    // cout << "Test Result: ";
    // // for (int num : nextPermutation(nums)) cout << num << " ";
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     cout << nums[i]<<endl;
    // }
    // cout << endl;
    // // cout << rearrangeArray(nums) << endl;
}