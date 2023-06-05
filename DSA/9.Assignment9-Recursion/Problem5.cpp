
// **Question 5**

// Given an array of **arr**, the task is to find maximum element of that array using recursion.

// **Example 1:**

// Input: arr = {1, 4, 3, -5, -4, 8, 6};
// Output: 8

// **Example 2:**

// Input: arr = {1, 4, 45, 6, 10, -8};
// Output: 45


#include <bits/stdc++.h>
using namespace std;

// Approach 1 : Using recursion
// - Time Complexity : O(n)
// - Space Complexity : O(n)
int maxElementApproach1(vector<int> arr, int n){
	if(n== 0) return arr[0];
	return max(arr[n-1], maxElementApproach1(arr, n-2));
}

// Approach 2 : Using sorting
// - Time Complexity : O(nlogn)
// - Space Complexity : O(1)
int maxElementApproach2(vector<int> arr, int n){
	sort(arr.begin(), arr.end());
	return arr[arr.size()-1];
}

// Approach 3 : Using loop
// - Time Complexity : O(n)
// - Space Complexity : O(1)
int maxElementApproach3(vector<int> arr, int n){
	int mx= INT_MIN;
	for(int i=0; i<n; i++)
		mx= max(mx, arr[i]);
	return mx;
}

int main(){
	vector<int> ans{1, 4, 45, 6, 10, -8};
	int max;
	max= maxElementApproach1(ans, ans.size());
	// max= maxElementApproach2(ans, ans.size());
	// max= maxElementApproach3(ans, ans.size());
	cout << max << endl;
	return 0;
}