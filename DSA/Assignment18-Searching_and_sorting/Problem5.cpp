// Time Complexity : O(1)
// Space Complexity : O(n)

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> numSet;

    for (int num : nums) {
        if (numSet.count(num) > 0) {
            return true;
        }
        numSet.insert(num);
    }

    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    bool hasDuplicate = containsDuplicate(nums);

    if (hasDuplicate) {
        cout << "The array contains duplicates." << endl;
    } else {
        cout << "The array does not contain duplicates." << endl;
    }

    return 0;
}
