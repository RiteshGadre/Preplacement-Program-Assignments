// **Question 4**

// Given a number N and a power P, the task is to find the exponent of this number raised to the given power, i.e. N^P.

// **Example 1 :** 

// Input: N = 5, P = 2

// Output: 25

// **Example 2 :**
// Input: N = 2, P = 5

// Output: 32


#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Space COmplexity : O(n)
int power(int n, int p){
	if(p==0) return 1;
	return n* power(n, p-1);
}
int main(){
	cout << power(5, 2) << endl;
	cout << power(2, 5) << endl;
	return 0;
}