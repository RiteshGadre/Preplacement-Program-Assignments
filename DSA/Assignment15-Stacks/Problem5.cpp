// Time Complexity : O(n)
// Space Complexity : O(n)


#include <bits/stdc++.h>
using namespace std;

string reverseString(const string& str) {
    stack<char> st;

    for (char ch : str) {
        st.push(ch);
    }

    string reversedStr;

    while (!st.empty()) {
        reversedStr += st.top();
        st.pop();
    }

    return reversedStr;
}

int main() {
    string str = "GeeksforGeeks";
    cout << "Original String: " << str << endl;

    string reversedStr = reverseString(str);
    cout << "Reversed String: " << reversedStr << endl;

    return 0;
}
