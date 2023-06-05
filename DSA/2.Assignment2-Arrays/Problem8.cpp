// Question 8
// You are given an integer array nums and an integer k.

// In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.

// The score of nums is the difference between the maximum and minimum elements in nums.

// Return the minimum score of nums after applying the mentioned operation at most once for each index in it.

// Example 1:
// Input: nums = [1], k = 0
// Output: 0

// Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.



#include <bits/stdc++.h>
using namespace std;

// Approach : Sorting
// - Time Complexity : O(nlogn)
// - Space Complexity : O(1)

int smallestRangeI(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int diff;
    
    if(nums[nums.size()-1]-k>=nums[0]+k){
        diff=(nums[nums.size()-1]-k)-(nums[0]+k);
    }
    else{
        int fl=nums[nums.size()-1]-nums[0]+k;
        diff=nums[nums.size()-1]-fl-nums[0]+k;
    }
    return diff;
}

int main(){
	vector<int> nums{1};
	int k= 0;
	cout << smallestRangeI(nums, k) << endl;
}