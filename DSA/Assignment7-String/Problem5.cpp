#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Space Complexity : O(1)
string reverseStr(string s, int k) {
    int n = s.length();
    char* arr = &s[0];

    for (int i = 0; i < n; i += 2 * k) {
        int left = i;
        int right = min(i + k - 1, n - 1);

        while (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    return s;
}

int main() {
    string s = "abcdefg";
    int k = 2;
    string reversed = reverseStr(s, k);
    cout << "Reversed: " << reversed << endl;
    return 0;
}
