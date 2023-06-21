// Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> findNextGreaterFrequency(const vector<int>& arr) {
    unordered_map<int, int> frequency;
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int num : arr) {
        frequency[num]++;
    }

    for (int i = n - 1; i >= 0; i--) {
        int currFreq = frequency[arr[i]];

        while (!s.empty() && frequency[s.top()] <= currFreq) {
            s.pop();
        }

        if (!s.empty()) {
            result[i] = s.top();
        }

        s.push(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 1, 1, 2, 2, 2, 2, 11, 3, 3};
    vector<int> result = findNextGreaterFrequency(arr);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
