// Time Complexity : O(n)
// Space Complexity : O(n)

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int maxAbsDifference(const vector<int>& arr) {
    int n = arr.size();
    vector<int> LS(n, 0); // Nearest left smaller element
    vector<int> RS(n, 0); // Nearest right smaller element

    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() > arr[i]) {
            RS[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()) {
        RS[st.top()] = 0;
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() > arr[i]) {
            LS[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    while (!st.empty()) {
        LS[st.top()] = 0;
        st.pop();
    }

    int maxDiff = 0;
    for (int i = 0; i < n; i++) {
        int diff = abs(LS[i] - RS[i]);
        maxDiff = max(maxDiff, diff);
    }

    return maxDiff;
}

int main() {
    vector<int> arr1 = {2, 1, 8};
    cout << maxAbsDifference(arr1) << endl;

    vector<int> arr2 = {2, 4, 8, 7, 7, 9, 3};
    cout << maxAbsDifference(arr2) << endl;

}
