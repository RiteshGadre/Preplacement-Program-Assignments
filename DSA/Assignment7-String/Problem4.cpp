#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Space Complexity : O(n)
string reverseWords(string s) {
    string result;
    int start = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            reverse(s.begin() + start, s.begin() + i);
            result += s.substr(start, i - start) + ' ';
            start = i + 1;
        }
    }

    reverse(s.begin() + start, s.end());
    result += s.substr(start) + ' ';

    // Remove the trailing whitespace
    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}

int main() {
    string s = "Let's take LeetCode contest";
    string reversed = reverseWords(s);
    cout << reversed << endl;
    return 0;
}
