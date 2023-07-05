// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0;
    int majorityElement;

    for (int num : nums) {
        if (count == 0) {
            majorityElement = num;
            count++;
        } else if (majorityElement == num) {
            count++;
        } else {
            count--;
        }
    }

    return majorityElement;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int result = majorityElement(nums);
    cout << "Majority element: " << result << endl;
    return 0;
}
