// Time Complexity : O(n)
// Space Complexity : O(1)



#include <iostream>
#include <vector>

using namespace std;

int trapWater(const vector<int>& height) {
    int n = height.size();
    if (n < 3) {
        return 0;
    }

    int left = 0;
    int right = n - 1;
    int leftMax = 0;
    int rightMax = 0;
    int waterTrapped = 0;

    while (left < right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                waterTrapped += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                waterTrapped += rightMax - height[right];
            }
            right--;
        }
    }

    return waterTrapped;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int waterTrapped = trapWater(height);
    cout << waterTrapped << endl;

    return 0;
}
