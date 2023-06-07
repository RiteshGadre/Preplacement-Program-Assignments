#include <bits/stdc++.h>
using namespace std;


// Time Complexity : O(n)
// Space Complexity : O(1)
bool isStrobogrammatic(string num) {
    unordered_map<char, char> strobogrammaticMap{
        {'0', '0'},
        {'1', '1'},
        {'6', '9'},
        {'8', '8'},
        {'9', '6'}
    };

    int left = 0;
    int right = num.length() - 1;

    while (left <= right) {
        if (strobogrammaticMap.count(num[left]) == 0 ||
            strobogrammaticMap[num[left]] != num[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    string num = "69";
    bool result = isStrobogrammatic(num);
    cout << boolalpha << result << endl;
    return 0;
}
