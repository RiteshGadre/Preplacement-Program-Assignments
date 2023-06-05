// Question 7
// An array is monotonic if it is either monotone increasing or monotone decreasing.

// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is
// monotone decreasing if for all i <= j, nums[i] >= nums[j].

// Given an integer array nums, return true if the given array is monotonic, or false otherwise.

// Example 1:
// Input: nums = [1,2,2,3]
// Output: true


#include <bits/stdc++.h>
using namespace std;


// Approach : 2 pointer
// - Time Complexity : O(n)
// - Space Complexity : O(1)

bool isMonotonic(vector<int>& nums) {
    int count1=0,count2=0;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]<=nums[i+1])count1++;
        if(nums[i]>=nums[i+1])count2++;}
    return (count1==nums.size()-1 || count2==nums.size()-1);
}

int main(){
	vector<int> nums{1,2,2,3};
	bool ans= isMonotonic(nums);
	cout << ans << endl;
}