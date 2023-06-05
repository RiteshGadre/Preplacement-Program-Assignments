/*
💡 **Q3.** Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

**Example 1:**
Input: nums = [1,3,5,6], target = 5

Output: 2
*/



#include <bits/stdc++.h>
using namespace std;

// Approach 1: By iterating an array
// - Declare an int i, and initialize it with 0
// - Iterate it through whole array, untill it finds the element graeter or equal to target or until the last element
// - Increment the value of i as well
// - Return the value of i
// - Time Complexity : O(n)
// - Space Complecity : O(1)

int searchInsertApproach1(vector<int>& nums, int target) {
    int i=0;
    while(i<nums.size() && nums[i]< target){
        i++;
    }

    return i;   
}


// Approach 2: Using two pointer
// - Declare 2 integers start and end
// - Initialize start with 0 and end with no.of elements - 1
// - Corner Case : If target is less than first element return 0
// - Declare mid and assign it value of half of sum start and end
// - If nums[mid] is equal to target return mid
// - If nums[mid] is less than target, set start with mid+1
// - If nums[mid] is greater than target, set end with mid-1
// - Now come out of loop
// - If element is less than start return start, other wise return end+1
// - Time Cmplexity : O(n)
// - Space Complexity : O(1)

int searchInsertApproach2(vector<int>& nums, int target) {
    int start=0, end= nums.size()-1;
    if(target < nums[0]) return 0;
    while(start<= end){
        int mid= (start+end)/2;
        if(nums[mid]== target)
            return mid;
        else if(nums[mid]< target)
            start= mid+1;
        else
            end= mid-1;
    }
    if(nums[end]<target) return end+1;
	return start;  
}

int main() {
	vector<int> nums={1, 3, 5, 6};
	int ans;
	ans= searchInsertApproach1(nums, 5);
	// ans= searchInsertApproach2(nums, 5);
	cout << ans << endl;
	return 0;
}
