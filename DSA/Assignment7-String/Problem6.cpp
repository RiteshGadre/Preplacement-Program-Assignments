#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(n*n)
// Space Complexity : O(n)
bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) {
        return false;
    }

    string s2 = s + s;
    return s2.find(goal) != string::npos;
}

int main() {
    string s = "abcde";
    string goal = "cdeab";
    bool canRotate = rotateString(s, goal);
    cout << boolalpha << canRotate << endl;
    return 0;
}
