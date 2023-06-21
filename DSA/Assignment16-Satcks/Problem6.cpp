// Time Complexity : O(n)
// Space Complexity : O(k)

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseKElements(queue<int>& q, int k) {
    if (k > q.size()) {
        return;
    }

    stack<int> st;

    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Dequeue the remaining elements and enqueue them back into the queue
    while (!q.empty()) {
        q.push(q.front());
        q.pop();
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    cout << "Before reversing first " << k << " elements: ";
    queue<int> qCopy = q;
    while (!qCopy.empty()) {
        cout << qCopy.front() << " ";
        qCopy.pop();
    }
    cout << endl;

    reverseKElements(q, k);

    cout << "After reversing first " << k << " elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
