// Question 1
// Convert 1D Array Into 2D Array
// You are given a 0-indexed 1-dimensional (1D) integer array original, and two integers, m and n. You are tasked with creating a 2-dimensional (2D) array with m rows and n columns using all the elements from original.
// The elements from indices 0 to n - 1 (inclusive) of original should form the first row of the constructed 2D array, the elements from indices n to 2 * n - 1 (inclusive) should form the second row of the constructed 2D array, and so on.
// Return an m x n 2D array constructed according to the above procedure, or an empty 2D array if it is impossible.

// Example
// Input: original = [1,2,3,4], m = 2, n = 2
// Output: [[1,2],[3,4]]
// Explanation: The constructed 2D array should contain 2 rows and 2 columns.
// The first group of n=2 elements in original, [1,2], becomes the first row in the constructed 2D array.
// The second group of n=2 elements in original, [3,4], becomes the second row in the constructed 2D array.


#include <bits/stdc++.h>
using namespace std;


// Time complexity : O(m*n)
// Space complexity : O(m*n)
vector<vector<int>> convertTo2DArray(const vector<int>& original, int m, int n) {
    int size = original.size();
    if (m * n != size) {
        return {};
    }
    
    vector<vector<int>> result(m, vector<int>(n));
    
    for (int i = 0; i < size; i++) {
        int row = i / n;  
        int col = i % n;  
        result[row][col] = original[i];
    }
    
    return result;
}

int main() {
    vector<int> original = {1, 2, 3, 4};
    int m = 2, n = 2;
    
    vector<vector<int>> result = convertTo2DArray(original, m, n);
    
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
