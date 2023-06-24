// Time Complexity : O(n)
// Space Complexity : O(1)

#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0;        // Pointer for 0's
    int high = n - 1;   // Pointer for 2's

    int i = 0;
    while (i <= high) {
        if (nums[i] == 0) {
            swap(nums[i], nums[low]);
            low++;
            i++;
        } else if (nums[i] == 2) {
            swap(nums[i], nums[high]);
            high--;
        } else {
            i++;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Original Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    sortColors(nums);

    cout << "Sorted Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
