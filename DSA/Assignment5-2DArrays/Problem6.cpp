// Question 6

// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appear twice.
// You must write an algorithm that runs in O(n) time and uses only constant extra space.

// Example 1:
// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]


#include <bits/stdc++.h>

using namespace std;


// Time Complexity : O(n)
// Space Complexity : O(1)
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    
    for (int num : nums) {
        int index = abs(num) - 1;
        
        if (nums[index] < 0) {
            result.push_back(index + 1);
        } else {
            nums[index] = -nums[index];
        }
    }
    
    for (int& num : nums) {
        num = abs(num);
    }
    
    return result;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    
    vector<int> duplicates = findDuplicates(nums);
    
    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}

