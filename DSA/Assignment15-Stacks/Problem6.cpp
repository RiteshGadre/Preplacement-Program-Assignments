// Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

int evaluatePostfixExpression(const string& postfixExpression) {
    stack<int> st;

    for (char ch : postfixExpression) {
        if (isdigit(ch)) {
            st.push(ch - '0');
        } else {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();

            int result;
            if (ch == '+') {
                result = operand1 + operand2;
            } else if (ch == '-') {
                result = operand1 - operand2;
            } else if (ch == '*') {
                result = operand1 * operand2;
            } else if (ch == '/') {
                result = operand1 / operand2;
            } else {
                cout << "Invalid operator: " << ch << endl;
                return 0;
            }

            st.push(result);
        }
    }

    return st.top();
}

int main() {
    string postfixExpression = "231*+9-";
    int result = evaluatePostfixExpression(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}
