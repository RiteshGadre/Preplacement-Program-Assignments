#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute force
// - Use 2 loops, outer for traversing arrany and inner for maintining the count of elements
// - If count is grater than 2 return true
// - Return false
// - Time Complexity : O(N*N)
// - Space Complexity : O(1)
bool containsDuplicateApproach1(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++){
        int count= 0;
        for(int j=0; j<nums.size(); j++){
            count+= (nums[i]== nums[j]);
            if(count > 1) return true;
        }
    }
    return false;
}


// Approach 2: Sorting
// - Sort the array
// - Iterate the array from second element and compare every element with its previous element
// - Return true if we found last element is equal to current element
// - Return False
// - Time Complexity : O(NlogN)
// - Space Complexity : O(1)

bool containsDuplicateApproach2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for(int i=1; i<nums.size(); i++){
        if(nums[i]==nums[i-1]) return true;
    }
    return false;
}


// Approach 3: Using hashmap
// - Delare hashmap and store the elements inside it with its count
// - Return true if count of element is 2
// - Return false
// - Time Complexity : O(N)
// - Space Complexity : O(N)

bool containsDuplicateApproach3(vector<int>& nums) {
    unordered_map<int, int> map;
    for(auto it: nums) {
        map[it]++;
        if(map[it]>1) return true;
    }
    return false;
}



int main() {
	vector<int> nums{1, 2, 3, 1};
	bool ans;
	ans= containsDuplicateApproach1(nums);
	// ans= containsDuplicateApproach2(nums);
	// ans= containsDuplicateApproach3(nums);
	cout << ans << endl;
	return 0;
}