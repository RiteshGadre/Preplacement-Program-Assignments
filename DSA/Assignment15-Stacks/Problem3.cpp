// Time Complexity : O(1)
// Space Complexity : O(n)


#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int val) {
        q1.push(val);
    }

    int pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1; // Return a sentinel value
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int poppedElement = q1.front();
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);

        return poppedElement;
    }

    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    Stack stack;
    stack.push(2);
    stack.push(3);
    cout << stack.pop() << endl;
    stack.push(4);
    cout << stack.pop() << endl;

    return 0;
}
