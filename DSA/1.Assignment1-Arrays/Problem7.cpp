/*
**Q7.** Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the nonzero elements.

Note that you must do this in-place without making a copy of the array.

**Example 1:**
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/



#include <bits/stdc++.h>
using namespace std;

// Approach 1: using extra space
// - Declare duplicate array and all non-negative elements in from main array
// - Now copy the duplicate array into main array
// - For remaning positions add 0 in it
// - Time Complexity : O(n)
// - Space Coplexity : O(n)

void moveZeroesApproach1(vector<int>& nums) {
    int i= 0;
    for(int j=0; j<nums.size(); j++){
        if(nums[j]) nums[i++]= nums[j];
    }
    for(; i<nums.size(); i++) nums[i]= 0;
}


// Approach 2: Without using extra space
// - Declare var a and initialize it with 0
// - Run the loop and swap the non negative element with ith value
// - For remaining positions add 0
// - Time Complexity : O(n)
// - Space Complexity : O(1)

void moveZeroesApproach2(vector<int>& nums) {
    int i= 0;
    for(int j=0; j<nums.size(); j++){
        if(nums[j]) nums[i++]= nums[j];
    }
    for(; i<nums.size(); i++) nums[i]= 0;
}

int main(){
	vector<int> nums{0, 1, 0, 3, 12};
	moveZeroesApproach1(nums);
	// moveZeroesApproach2(nums);
	for(auto it: nums) cout << it << " ";
	return 0;
}
