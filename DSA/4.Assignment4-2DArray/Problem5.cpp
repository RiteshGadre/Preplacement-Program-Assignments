// **Question 5**
// You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase **may be** incomplete.

// Given the integer n, return *the number of **complete rows** of the staircase you will build*.

// **Example 1:**

// []()


// **Input:** n = 5

// **Output:** 2

// **Explanation:** Because the 3rd row is incomplete, we return 2.



#include <bits/stdc++.h>
using namespace std;

// Approach : Bruete force
// - Time Complexity : O(n)
// - Space Complexity : O(1)
int arrangeCoins(int n) {      
    int count = 1;
    while(n>0)
    {
        if(n>=count)
        {
            n = n-count;
            count++; 
        }
        else
        {
           n = n-count;
        }
    }
    return count-1;
}


int main(){
	cout << arrangeCoins(5) << endl;
	return 0;
}