// Time Complexity: O(logn)
// Space Complexity: O(k)

#include <iostream>
#include <vector>
using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int left = 0;
    int right = arr.size() - 1;

    while (right - left >= k) {
        if (abs(arr[left] - x) > abs(arr[right] - x)) {
            left++;
        } else {
            right--;
        }
    }

    vector<int> result(arr.begin() + left, arr.begin() + right + 1);

    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;
    vector<int> result = findClosestElements(arr, k, x);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
