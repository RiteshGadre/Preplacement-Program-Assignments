// **Question 6**

// An integer array `original` is transformed into a doubled array `changed` by appending twice the value of every element in `original` and then randomly shuffling the resulting array.

// Given an array `changed`, return `original` if `changed` is a doubled array. If `changed` is not a doubled array, return an empty array. The elements in `original` may be returned in any order.

// **Example 1:**

// **Input:** `changed = [1,3,4,2,6,8]`

// **Output:** `[1,3,4]`


#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Space Complexity : O(n)
vector<int> findOriginalArray(vector<int>& changed) {
    int n = changed.size();
    vector<int> original;

    if (n % 2 != 0) {
        return original;
    }

    unordered_map<int, int> freq;

    for (int num : changed) {
        freq[num]++;
    }

    for (int num : changed) {
        if (freq[num] > 0 && freq[2 * num] > 0) {
            original.push_back(num);
            freq[num]--;
            freq[2 * num]--;
        }
    }

    if (original.size() != n / 2) {
        original.clear();
    }

    return original;
}

int main() {
    vector<int> changed = {1, 3, 4, 2, 6, 8};

    vector<int> original = findOriginalArray(changed);

    if (original.empty()) {
        cout << "Empty Array" << endl;
    } 
    else {
        for (int num : original) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
