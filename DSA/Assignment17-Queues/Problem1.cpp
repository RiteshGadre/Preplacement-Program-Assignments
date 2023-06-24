// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> countMap;
    queue<char> uniqueQueue;
    
    for (char c : s) {
        countMap[c]++;
        if (countMap[c] == 1) {
            uniqueQueue.push(c);
        } else {
            while (!uniqueQueue.empty() && countMap[uniqueQueue.front()] > 1) {
                uniqueQueue.pop();
            }
        }
    }
    
    while (!uniqueQueue.empty()) {
        if (countMap[uniqueQueue.front()] == 1) {
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == uniqueQueue.front()) {
                    return i;
                }
            }
        }
        uniqueQueue.pop();
    }
    
    return -1;
}

int main() {
    string s1 = "leetcode";
    int index1 = firstUniqChar(s1);
    cout << index1 << endl;
    
    string s2 = "loveleetcode";
    int index2 = firstUniqChar(s2);
    cout << index2 << endl;

    string s3 = "aabb";
    int index3 = firstUniqChar(s3);
    cout << index3 << endl;
    return 0;
}
