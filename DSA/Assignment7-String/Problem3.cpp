#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(max(num1, num2))
// Space Complexity : O(max(num1, num2))
string addStrings(string num1, string num2) {
    string result;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        int tempSum = digit1 + digit2 + carry;
        carry = tempSum / 10;
        result.push_back(tempSum % 10 + '0');

        i--;
        j--;
    }

    if (carry > 0) {
        result.push_back(carry + '0');
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string num1 = "11";
    string num2 = "123";
    string sum = addStrings(num1, num2);
    cout << sum << endl;
    return 0;
}
