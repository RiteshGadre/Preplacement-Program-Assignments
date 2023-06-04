// **Question 2**

// Given a number n, find the sum of the first natural numbers.

// **Example 1:**

// Input: n = 3 

// Output: 6

// **Example 2:**

// Input  : 5 

// Output : 15

#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Using Recursion
// - Time Complexity : O(n)
// - Space Complexity : O(n)
int findSumApproach1(int n){
	if(n==0 || n==1) return n;
	return n+ findSumApproach1(n-1);
}


// Approach 2 : Using loop
// - Time Complexity : O(n)
// - Space Complexity : O(1)
int findSumApproach2(int n){
	int sum= 0;
	for(int i=1; i<=n; i++) sum+= i;
	return sum;
}


// Approach 3 : Using bit manipulation
// - Time Complexity : O(1)
// - Space Complexity : O(1)
int findSumApproach3(int n){
	return n*(n+1)/2;
}


int main(){
	int ans;
	ans= findSumApproach1(5);
	// ans= findSumApproach2(8);
	// ans= findSumApproach3(5);
	cout << ans << endl;
}