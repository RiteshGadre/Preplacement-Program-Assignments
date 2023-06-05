// Given a positive integer, N. Find the factorial of N. 

// **Example 1:**

// Input: N = 5 

// Output: 120

// **Example 2:**

// Input: N = 4

// Output: 24


#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// space Complexity : O(n)
int fact(int n){
	if(n==1) return n;
	return n*fact(n-1);
}

int main(){
	cout << fact(5) << endl;
	return 0;
}