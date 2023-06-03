//  **Question 6**
// Given an integer array nums sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.

// **Example 1:**

// Input: nums = [-4,-1,0,3,10]

// Output: [0,1,9,16,100]

// **Explanation:** After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100]





#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Space Complexity : O(n)
vector<int> sortedSquares(vector<int>& nums) {
   int n = nums.size(), s = 0, e = n - 1;
   vector<int> ans(n);
   
   for(int i=n-1; i>=0; i--) {
       if(abs(nums[s]) < abs(nums[e])) ans[i] = nums[e] * nums[e--];
       else ans[i] = nums[s] * nums[s++];
   }
   return ans;
}

int main(){
	vector<int> nums{-4, -1, 0, 3, 10};
	vector<int> ans= sortedSquares(nums);
	for(auto it : ans) cout << it << " ";
	cout << endl;
	return 0;	
}