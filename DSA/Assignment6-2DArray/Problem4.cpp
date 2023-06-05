// Question 4
// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

// Example 1:
// Input: nums = [0,1]
// Output: 2


#include <bits/stdc++.h>
using namespace std;


// Time Complexity : O(n)
// Space Complexity : O(n)
int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> countMap;
    int maxLength = 0;
    int count = 0;

    // Initialize countMap with initial count 0 at index 0
    countMap[0] = -1;

    for (int i = 0; i < n; i++) {
        // Increment count for 1, decrement count for 0
        count += nums[i] == 1 ? 1 : -1;

        // Check if count is already present in countMap
        if (countMap.find(count) != countMap.end()) {
            // Calculate the length of the subarray with equal 0s and 1s
            int length = i - countMap[count];
            maxLength = max(maxLength, length);
        } else {
            // Store the first occurrence of count in countMap
            countMap[count] = i;
        }
    }

    return maxLength;
}

int main() {
    vector<int> nums = {0, 1};

    int maxLength = findMaxLength(nums);

    cout << maxLength << endl;

    return 0;
}
