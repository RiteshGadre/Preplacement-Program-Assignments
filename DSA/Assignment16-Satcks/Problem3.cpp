// Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

void deleteMiddle(stack<int>& st, int current, int middle) {
    if (current == middle) {
        st.pop();
        return;
    }

    int temp = st.top();
    st.pop();

    deleteMiddle(st, current + 1, middle);

    st.push(temp);
}

void deleteMiddleElement(stack<int>& st) {
    int size = st.size();
    int middle = (size / 2) + 1;

    deleteMiddle(st, 1, middle);
}

int main() {
    stack<int> st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.push(4);
    st1.push(5);

    cout << "Input: ";
    stack<int> st1Copy = st1;
    while (!st1Copy.empty()) {
        cout << st1Copy.top() << " ";
        st1Copy.pop();
    }
    cout << endl;

    deleteMiddleElement(st1);

    cout << "Output: ";
    while (!st1.empty()) {
        cout << st1.top() << " ";
        st1.pop();
    }
    cout << endl;

    stack<int> st2;
    st2.push(1);
    st2.push(2);
    st2.push(3);
    st2.push(4);
    st2.push(5);
    st2.push(6);

    cout << "Input: ";
    stack<int> st2Copy = st2;
    while (!st2Copy.empty()) {
        cout << st2Copy.top() << " ";
        st2Copy.pop();
    }
    cout << endl;

    deleteMiddleElement(st2);

    cout << "Output: ";
    while (!st2.empty()) {
        cout << st2.top() << " ";
        st2.pop();
    }
    cout << endl;

    return 0;
}
