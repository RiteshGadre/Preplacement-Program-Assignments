// Time Complexity : O(n)
// Space Complexity : O(n)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) {
        return 0;
    }

    int maxNum = *max_element(nums.begin(), nums.end());

    int exp = 1;
    vector<int> sorted(nums.size());

    while (maxNum / exp > 0) {
        vector<int> count(10, 0);

        for (int num : nums) {
            int digit = (num / exp) % 10;
            count[digit]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            int digit = (nums[i] / exp) % 10;
            sorted[count[digit] - 1] = nums[i];
            count[digit]--;
        }

        nums = sorted;
        exp *= 10;
    }

    int maxDiff = 0;
    for (int i = 1; i < nums.size(); i++) {
        maxDiff = max(maxDiff, nums[i] - nums[i - 1]);
    }

    return maxDiff;
}

int main() {
    vector<int> nums = {3, 6, 9, 1};
    int maxDiff = maximumGap(nums);

    cout << "Maximum difference: " << maxDiff << endl;

    return 0;
}
