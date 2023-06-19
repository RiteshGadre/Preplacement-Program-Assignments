// Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> findNearestSmallerElements(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            result[i] = st.top();
        }

        st.push(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 5, 0, 3, 4, 5};
    vector<int> result = findNearestSmallerElements(arr);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
