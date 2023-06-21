// Time Complexity : O(logn)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

int reverseNumber(int number) {
    stack<int> st;

    while (number != 0) {
        int digit = number % 10;
        st.push(digit);
        number /= 10;
    }

    int reversedNumber = 0;
    int placeValue = 1;

    // Pop the digits from the stack and construct the reversed number
    while (!st.empty()) {
        int digit = st.top();
        reversedNumber += digit * placeValue;
        placeValue *= 10;
        st.pop();
    }

    return reversedNumber;
}

int main() {
    int number1 = 365;
    cout << "Output: " << reverseNumber(number1) << endl;

    int number2 = 6899;
    cout << "Output: " << reverseNumber(number2) << endl;

    return 0;
}
