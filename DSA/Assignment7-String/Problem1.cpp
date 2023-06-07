// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// Example 1
// Input s = "egg", t = "add"
// Output: true


#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
// Space Complexity : O(k)
bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, char> s_to_t;
    unordered_map<char, char> t_to_s;

    for (int i = 0; i < s.length(); i++) {
        char c_s = s[i];
        char c_t = t[i];

        if (s_to_t.count(c_s)) {
            if (s_to_t[c_s] != c_t) {
                return false;
            }
        } else {
            s_to_t[c_s] = c_t;
        }

        if (t_to_s.count(c_t)) {
            if (t_to_s[c_t] != c_s) {
                return false;
            }
        } else {
            t_to_s[c_t] = c_s;
        }
    }

    return true;
}

int main() {
    string s = "egg";
    string t = "add";

    cout << (isIsomorphic(s, t) ? "true" : "flase") << endl;

    return 0;
}
