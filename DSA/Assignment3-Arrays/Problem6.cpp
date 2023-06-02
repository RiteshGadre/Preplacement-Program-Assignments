// Question 6
// Given a non-empty array of integers nums, every element appears twice except
// for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only
// constant extra space.

// Example 1:
// Input: nums = [2,2,1]
// Output: 1


#include<bits/stdc++.h>
using namespace std;

// Approach 1: Sorting
// - Time Complexity : O(nlogn)
// - Space Complexity : O(1)
int singleNumberApproach1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(int i=1; i<nums.size(); i+= 2){
        if(nums[i]!= nums[i-1]) return nums[i-1];
    }
    return nums[nums.size()-1];
}

// Approach 2: Hashmap
// - Time Complexity : O(n)
// - Space Complexity : O(n)
int singleNumberApproach2(vector<int>& nums) {
    unordered_map<int, int> map;
    for(auto it: nums) map[it]++;
    for(auto it: nums) 
        if(map[it]== 1) return it;
    return -1;
}

// Approach 3: Using XOR
// - Time Complexity : O(n)
// - Space Complexity : O(1)
int singleNumberApproach3(vector<int>& nums) {
    int ans= nums[0];
    for(int i=1; i<nums.size(); i++){
        ans^= nums[i];
    }
    return ans;
}

int main(){
	vector<int> nums{2, 2, 1, 3, 1};
	int ans;
	ans= singleNumberApproach1(nums);
	ans= singleNumberApproach2(nums);
	ans= singleNumberApproach3(nums);
	cout << ans << endl;
}