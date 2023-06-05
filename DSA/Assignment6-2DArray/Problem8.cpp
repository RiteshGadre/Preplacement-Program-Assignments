// **Question 8**

// Given two [sparse matrices](https://en.wikipedia.org/wiki/Sparse_matrix) mat1 of size m x k and mat2 of size k x n, return the result of mat1 x mat2. You may assume that multiplication is always possible.
// Example 1:
// Input: mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]
// Output:
// [[7,0,0],[-7,0,3]]


#include <bits/stdc++.h>
using namespace std;


// Time Complexity : O(m*n*k)
// Space Complexity : O(m*n)
vector<vector<int>> multiplySparseMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int m = mat1.size();
    int k = mat1[0].size();
    int n = mat2[0].size();

    vector<vector<int>> result(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < k; p++) {
                result[i][j] += mat1[i][p] * mat2[p][j];
            }
        }
    }

    return result;
}

void printMatrix(const vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> mat1 = {{1, 0, 0}, {-1, 0, 3}};
    vector<vector<int>> mat2 = {{7, 0, 0}, {0, 0, 0}, {0, 0, 1}};

    vector<vector<int>> result = multiplySparseMatrices(mat1, mat2);
    printMatrix(result);

    return 0;
}
