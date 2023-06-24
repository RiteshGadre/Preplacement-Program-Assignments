// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;
    int maxSum = INT_MIN;
    int minSum = INT_MAX;
    int currMax = 0;
    int currMin = 0;

    for (int i = 0; i < n; i++) {
        currMax = max(currMax + nums[i], nums[i]);
        maxSum = max(maxSum, currMax);

        currMin = min(currMin + nums[i], nums[i]);
        minSum = min(minSum, currMin);

        totalSum += nums[i];
    }

    if (maxSum > 0) {
        int circularSum = totalSum - minSum;
        maxSum = max(maxSum, circularSum);
    }

    return maxSum;
}

int main() {
    vector<int> nums = {1, -2, 3, -2};
    int maxSum = maxSubarraySumCircular(nums);
    cout << maxSum << endl;

    return 0;
}
