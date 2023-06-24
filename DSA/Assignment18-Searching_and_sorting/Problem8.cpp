// Time Complexity : O(n)
// Space Complexity : O(n)

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) {
        return false;
    }

    vector<int> minPrefix(n);
    minPrefix[0] = nums[0];
    for (int i = 1; i < n; i++) {
        minPrefix[i] = min(minPrefix[i - 1], nums[i]);
    }

    stack<int> stk;
    for (int j = n - 1; j >= 0; j--) {
        if (nums[j] > minPrefix[j]) {
            while (!stk.empty() && stk.top() <= minPrefix[j]) {
                stk.pop();
            }
            if (!stk.empty() && stk.top() < nums[j]) {
                return true;
            }
            stk.push(nums[j]);
        }
    }

    return false;
}

int main() {
    vector<int> nums = {3, 1, 4, 2};
    bool has132pattern = find132pattern(nums);

    cout << (has132pattern ? "True" : "False") << endl;

    return 0;
}
