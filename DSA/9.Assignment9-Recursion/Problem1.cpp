// Question 1

// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2x.

// **Example 1:**
// Input: n = 1 
// Output: true

// **Example 2:**
// Input: n = 16 
// Output: true

// **Example 3:**
// Input: n = 3 
// Output: false


#include <bits/stdc++.h>
using namespace std;

// Approach1: Recursion
// - Time Complexity : log(n)
// - Space Complexity : log(n)

bool isPowerOfTwo(int n) {
    if(n==1 || n==0) return n;
    return (n%2==0 && isPowerOfTwo(n/2));    
}

int main(){
	int n=7;
	cout << isPowerOfTwo(n) << endl;
}	