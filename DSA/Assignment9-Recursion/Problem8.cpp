// **Question 8**

// Given an array, find a product of all array elements.

// **Example 1:**

// Input  : arr[] = {1, 2, 3, 4, 5}
// Output : 120
// **Example 2:**

// Input  : arr[] = {1, 6, 3}
// Output : 18


#include <bits/stdc++.h>
using namespace std;

// Approach1 : Using Recursion
// - Time Complexity : O(n)
// - Space Complexity : O(n)
int prodArr(vector<int> nums, int n){
	if(n==0) return nums[0];
	return nums[n-1] * prodArr(nums, n-1);
}

int main(){
	vector<int> nums{1, 2, 3, 4, 5};
	cout << prodArr(nums, nums.size()) << endl;
	return 0;
}