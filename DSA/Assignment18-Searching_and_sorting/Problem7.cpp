// Time Complexity : O(n^2)
// Space Complexity : O(n)

#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxLength = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }

    return maxLength;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int length = lengthOfLIS(nums);

    cout << "Length of the longest increasing subsequence: " << length << endl;

    return 0;
}
