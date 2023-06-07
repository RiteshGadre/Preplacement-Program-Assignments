


#include<bits/stdc++.h> 
using namespace std;

// Time Complexity : O(m+n)
// Space Complexity : O(m+n)
bool backspaceCompare(string s, string t) {
    stack<char> stackS, stackT;

    for (char c : s) {
        if (c != '#') {
            stackS.push(c);
        } else if (!stackS.empty()) {
            stackS.pop();
        }
    }

    for (char c : t) {
        if (c != '#') {
            stackT.push(c);
        } else if (!stackT.empty()) {
            stackT.pop();
        }
    }

    return stackS == stackT;
}

int main() {
    string s = "ab#c";
    string t = "ad#c";
    bool isEqual = backspaceCompare(s, t);
    cout << (isEqual ? "true" : "false") << endl;
    return 0;
}
