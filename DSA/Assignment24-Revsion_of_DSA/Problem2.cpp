// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    unordered_set<char> uniqueChars;
    int maxLength = 0;
    int i = 0, j = 0;

    while (i < n && j < n) {
        if (uniqueChars.find(s[j]) == uniqueChars.end()) {
            // If the current character is not in the set, add it to the set
            uniqueChars.insert(s[j++]);
            maxLength = max(maxLength, j - i);
        } else {
            uniqueChars.erase(s[i++]);
        }
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    cout << result << endl;
    return 0;
}
