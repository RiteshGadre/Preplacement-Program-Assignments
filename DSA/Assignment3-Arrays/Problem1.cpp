/*
Question 1
Given an integer array nums of length n and an integer target, find three integers
in nums such that the sum is closest to the target.
Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2

Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force 
// - Time Complexity : O(n*n*n)
// - Space Complexity : O(1)

int threeSumClosestApproach1(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
	int minDiff= INT_MAX;
    int minSum= INT_MAX;
	for(int i=0; i<nums.size()-2; i++){
        for(int j= i+1; j<nums.size()-1; j++){
            for(int k=j+1; k<nums.size(); k++){
                int sum= nums[i]+nums[j]+nums[k];
			    int currDiff= abs(target- sum);
			    if(currDiff < minDiff) {
                    minDiff = currDiff;
                    minSum= sum;
                }
            }
        }
    }  	
    return minSum;
}

// Approach 2: Using 2 pointer by sorting an array in non-decreasing order
// - Sort the array
// - Define 2 variables minDiff and minSum
// - minDiff will store closest elements to target, along with maintaining minSum a well
// - Time Complexity : O(n*n)
// - Space Complexity : O(1)

int threeSumClosestApproach2(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	int minDiff= INT_MAX;
	int minSum= INT_MAX;
	for(int i=0; i<nums.size()-2; i++){
		int start= i+1;
		int end= nums.size()-1;
		while(start<end){
			int sum= nums[i]+nums[start]+nums[end];
			int currDiff= abs(target- sum);
			if(currDiff < minDiff) {
	            minDiff = currDiff;
	            minSum= sum;
	        }
			if(sum < target) start++;
			else end--;
		}
	}
	return minSum;
}

int main(){
	vector<int> nums{-1, 2, 1, -4};
	int target= 1;
	int ans;
	ans= threeSumClosestApproach1(nums, target);
	ans= threeSumClosestApproach2(nums, target);
	cout << ans << endl;
	return 0;
}