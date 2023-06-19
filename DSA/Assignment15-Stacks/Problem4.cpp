// Time Complexity : O(n*n)
// Space Complexity : O(n)


#include <bits/stdc++.h>    
using namespace std;

void insertAtBottom(stack<int>& st, int element) {
    if (st.empty()) {
        st.push(element);
        return;
    }

    int topElement = st.top();
    st.pop();
    insertAtBottom(st, element);
    st.push(topElement);
}

void reverseStack(stack<int>& st) {
    if (st.empty() || st.size() == 1) {
        return;
    }

    int topElement = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, topElement);
}

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(7);
    st.push(6);

    cout << "Original Stack: ";
    printStack(st);

    reverseStack(st);

    cout << "Reversed Stack: ";
    printStack(st);

    return 0;
}
