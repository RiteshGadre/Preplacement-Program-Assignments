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