#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
    void setZeroes(vector<vector<int> >& matrix) {
        bool row1 = false;
        bool col1 = false;
        int m = matrix.size();
        int n = matrix[0].size();
        if(matrix[0][0] == 0){
            row1 = true;
            col1 = true;
        }
        for (int i = 1; i < m && (col1 == false || row1 == false); i++)
        {
            if(matrix[i][0]==0){
                col1 = true;
            }
        }
        for (int i = 1; i < n && (col1 == false || row1 == false); i++)
        {
            if(matrix[0][i]==0){
                row1 = true;
            }
        }
        
        for (int i = 1; i < m ; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
            
        }
        for (int i = 1; i < m; i++)
        {
            if(matrix[i][0]==0){
                for (int j = 1; j < n; j++)
                {
                    matrix[i][j]=0;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            if(matrix[0][i]==0){
                for (int j = 1; j < m; j++)
                {
                    matrix[j][i]=0;
                }
            }
        }
        if(col1){
            for (int j = 0; j < m; j++){
                matrix[j][0]=0;
            }
        }
        if(row1){
            for (int j = 0; j < n; j++){
                matrix[0][j]=0;
                // cout<<row1<<endl;
            }
        }

    }
    

int main(){
    // matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    // Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

// Matrix-1 : 4*3
    vector<vector<int> > matrix1;
    // vector<int> row1;
    // row1.push_back(0);
    // row1.push_back(1);
    // row1.push_back(3);
    // row1.push_back(2);
    // matrix1.push_back(row1);

    // vector<int> row2;
    // row2.push_back(2);
    // row2.push_back(4);
    // row2.push_back(0);
    // row2.push_back(1);
    // matrix1.push_back(row2);

    vector<int> row3;
    // row3.push_back(3);
    // row3.push_back(4);
    row3.push_back(1);
    row3.push_back(0);
    matrix1.push_back(row3);

    // [[1,0]]

    // nums.push_back(-5);
    // nums.push_back(2);
    // nums.push_back(-4);

    setZeroes(matrix1);

    cout << "Test Result: ";
    // for (int num : setZeroes(nums)) cout << num << " ";
    for (int i = 0; i < matrix1.size(); ++i) {
        for (int j = 0; j < matrix1[i].size(); ++j) {
            cout << matrix1[i][j] << " ";  // Print each element
        }
        cout << endl;  // Newline after each row
    }
    cout << endl;
    // cout << setZeroes(nums) << endl;
}