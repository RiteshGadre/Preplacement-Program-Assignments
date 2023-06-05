// Question 4
// Given a sorted array of distinct integers and a target value, return the index if the
// target is found. If not, return the index where it would be if it were inserted in
// order.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [1,3,5,6], target = 5
// Output: 2



#include <bits/stdc++.h>
using namespace std;


// Approach : Using Binary Search
// Time Complexity : O(logn)
// Space Complexity : O(1)
int searchInsert(vector<int>& nums, int target) {
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

int main(){
	vector<int> nums{1,3,5,6};
	int target= 5;
	cout << searchInsert(nums, target) << endl;
}