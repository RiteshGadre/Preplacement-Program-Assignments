// Given first term (a), common difference (d) and a integer N of the Arithmetic Progression series, the task is to find Nth term of the series.

// **Example 1:**

// Input : a = 2 d = 1 N = 5
// Output : 6
// The 5th term of the series is : 6

// **Example 2:**

// Input : a = 5 d = 2 N = 10
// Output : 23
// The 10th term of the series is : 23


#include <bits/stdc++.h>
using namespace std;

// Approach1 : Using Recursion
// - Time Complexity : O(n)
// - Space Complexity : O(n)
int nthTermApproach1(int a, int d, int n){
	if(n== 1) return a;
	return nthTermApproach1(a+d, d, n-1);
}


// Approach1 : Using Formula
// - Time Complexity : O(1)
// - Space Complexity : O(1)
int nthTermApproach2(int a, int d, int n){
	return a+ (n-1)*d;
}

int main(){
	int ans;
	ans= nthTermApproach1(5, 2, 10);
	// ans= nthTermApproach1(5, 2, 10);
	cout << ans;
	return 0;
}