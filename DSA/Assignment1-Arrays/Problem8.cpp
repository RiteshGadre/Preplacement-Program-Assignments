/*
**Q8.** You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

**Example 1:**
Input: nums = [1,2,2,4]
Output: [2,3]
*/


#include <bits/stdc++.h>
using namespace std;

// Approach : Hashmap
// - Insert all elements in the array and maintain their count
// - Iterate map from 1 to nth number, and return the missing and duplicate element.
// - Time Complexity : O(n)
// - Space Complexity : O(n)

vector<int> findErrorNums(vector<int>& nums) {
    unordered_map<int, int> map;
    for(auto it: nums) map[it]++;
    int duplicate;
    int missing;
    for(int i=1; i<= nums.size(); i++){
        if(map[i] > 1) duplicate= i;
        if(map[i] == 0) missing= i;
    }
    return {duplicate, missing};
}

int main() {
	vector<int> nums{1, 2, 2, 4};
	vector<int> ans= findErrorNums(nums);
	for(auto it: ans) cout << it << " ";
}
