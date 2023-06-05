// Given a string S, the task is to write a program to print all permutations of a given string.

// **Example 1:**

// ***Input:***

// *S = “ABC”*

// ***Output:***

// *“ABC”, “ACB”, “BAC”, “BCA”, “CBA”, “CAB”*

// **Example 2:**

// ***Input:***

// *S = “XY”*

// ***Output:***

// *“XY”, “YX”*

#include <bits/stdc++.h>
using namespace std;

void f(vector<string>& res, string& str, vector<int>& vis, string& temp) {
    if (temp.size() == str.size()) {
        res.push_back(temp);
        return;
    }
    for (int i = 0; i < str.size(); i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            temp.push_back(str[i]);
            f(res, str, vis, temp);
            temp.pop_back();
            vis[i] = 0;
        }
    }
}

vector<string> permute(string& str) {
    vector<string> res;
    vector<int> vis(str.size(), 0);
    string temp;
    f(res, str, vis, temp);
    return res;
}

int main() {
	string input= "ABC";
    vector<string> ans = permute(input);
    for (const auto& s : ans) {
        cout << s << " ";
    }
    return 0;
}
