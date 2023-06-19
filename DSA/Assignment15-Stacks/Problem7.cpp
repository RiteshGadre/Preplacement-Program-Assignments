#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {}

    void push(int val) {
        st.push(val);

        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        if (st.empty()) {
            return;
        }

        int topElement = st.top();
        st.pop();

        if (topElement == minSt.top()) {
            minSt.pop();
        }
    }

    int top() {
        if (st.empty()) {
            return INT_MAX;
        }

        return st.top();
    }

    int getMin() {
        if (minSt.empty()) {
            return INT_MAX;
        }

        return minSt.top();
    }
};
