// Time Complexity : O(n)
// Space Complexity : O(n)


#include <bits/stdc++.h>
using namespace std;

vector<int> findNextGreaterElements(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
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
    vector<int> arr = {4, 8, 3, 2, 7, 6};
    vector<int> result = findNextGreaterElements(arr);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
