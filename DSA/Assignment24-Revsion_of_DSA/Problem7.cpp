// Time Complexity: O(n)
// Space Complexity: O(k)

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < k; i++) {
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (int i = k; i < nums.size(); i++) {
        result.push_back(nums[dq.front()]);

        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    if (!dq.empty()) {
        result.push_back(nums[dq.front()]);
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
