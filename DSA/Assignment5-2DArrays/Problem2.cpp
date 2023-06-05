// Question 2
// You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.
// Given the integer n, return the number of complete rows of the staircase you will build.

// Example 1:
// Input: n = 5
// Output: 2
// Explanation: Because the 3rd row is incomplete, we return 2.


#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(sqrt(n))
// Space Complexity : O(1)
int arrangeCoins(int n) {
    int completeRows = 0;
    int coins = n;
    int row = 1;
    
    while (coins >= row) {
        coins -= row;
        completeRows++;
        row++;
    }
    
    return completeRows;
}

int main() {
    int n = 5;
    int result = arrangeCoins(n);
    
    cout << result << endl;
    
    return 0;
}
