// Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

string checkQueueOrder(queue<int>& q) {
    stack<int> st;
    queue<int> secondQueue;

    while (!q.empty()) {
        if (!st.empty() && q.front() > st.top())
            return "No";

        while (!secondQueue.empty() && q.front() > secondQueue.front()) {
            st.push(secondQueue.front());
            secondQueue.pop();
        }

        secondQueue.push(q.front());
        q.pop();
    }

    while (!secondQueue.empty()) {
        st.push(secondQueue.front());
        secondQueue.pop();
    }

    int prev = INT_MIN;
    while (!st.empty()) {
        if (st.top() < prev)
            return "No";
        prev = st.top();
        st.pop();
    }

    return "Yes";
}

int main() {
    queue<int> q1;
    q1.push(5);
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);

    cout << "Input: ";
    queue<int> q1Copy = q1;
    while (!q1Copy.empty()) {
        cout << q1Copy.front() << " ";
        q1Copy.pop();
    }
    cout << endl;

    cout << "Output: " << checkQueueOrder(q1) << endl;

    queue<int> q2;
    q2.push(5);
    q2.push(1);
    q2.push(2);
    q2.push(6);
    q2.push(3);
    q2.push(4);

    cout << "Input: ";
    queue<int> q2Copy = q2;
    while (!q2Copy.empty()) {
        cout << q2Copy.front() << " ";
        q2Copy.pop();
    }
    cout << endl;

    cout << "Output: " << checkQueueOrder(q2) << endl;

    return 0;
}
