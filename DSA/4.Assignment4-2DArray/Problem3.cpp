// **Question 3**
// Given a 2D integer array matrix, return *the **transpose** of* matrix.

// The **transpose** of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

// **Example 1:**

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]

// Output: [[1,4,7],[2,5,8],[3,6,9]]



#include<bits/stdc++.h>
using namespace std;

// Approach : Brute Force
// - Time Complexity : O(m*n)
// - Space Complexity : O(m*n)

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
	//Creating auxiliary matrix of size nXm... n=matrix[0].size and m=matrix.size()
    vector<vector<int>> res(matrix[0].size(), vector<int>(matrix.size()));
    
    for(int i=0;i<matrix.size();i++) {
        for(int j=0;j<matrix[0].size();j++) {
            res[j][i] = matrix[i][j];
        }
    }
    return res;
}


int main(){
	vector<vector<int>> matrix{
		{1,2,3},
		{4,5,6}, 
		{7,8,9}
	};

	vector<vector<int>> ans= transpose(matrix);

	for(auto it: ans) {
		for(auto element : it)
			cout << element << " ";
		cout << endl;
	}

	return 0;
}