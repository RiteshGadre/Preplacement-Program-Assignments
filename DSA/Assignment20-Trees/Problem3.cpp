#include <iostream>
#include <vector>
using namespace std;

bool isValidBSTLevelOrder(vector<int>& levelOrder, int start, int end) {
    if (start > end)
        return true;

    int rootValue = levelOrder[start];
    int rightSubtreeIndex = -1;

    // Find the index where the right subtree starts
    for (int i = start + 1; i <= end; i++) {
        if (levelOrder[i] > rootValue) {
            rightSubtreeIndex = i;
            break;
        }
    }

    // Check if all elements after the right subtree index are greater than the root
    for (int i = rightSubtreeIndex; i <= end; i++) {
        if (levelOrder[i] <= rootValue)
            return false;
    }

    // Recursively check validity of left and right subtrees
    bool isLeftValid = isValidBSTLevelOrder(levelOrder, start + 1, rightSubtreeIndex - 1);
    bool isRightValid = isValidBSTLevelOrder(levelOrder, rightSubtreeIndex, end);

    return isLeftValid && isRightValid;
}

bool isValidBSTLevelOrder(vector<int>& levelOrder) {
    int n = levelOrder.size();
    return isValidBSTLevelOrder(levelOrder, 0, n - 1);
}

int main() {
    vector<int> levelOrder1 = { 7, 4, 12, 3, 6, 8, 1, 5, 10 };
    cout << (isValidBSTLevelOrder(levelOrder1) ? "Yes" : "No") << endl;

    vector<int> levelOrder2 = { 11, 6, 13, 5, 12, 10 };
    cout << (isValidBSTLevelOrder(levelOrder2) ? "Yes" : "No") << endl;

    return 0;
}
