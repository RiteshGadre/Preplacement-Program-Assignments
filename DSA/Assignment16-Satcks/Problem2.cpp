// Time Complexity : O(n*n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

stack<int> sortStack(stack<int>& inputStack) {
    stack<int> tempStack;

    while (!inputStack.empty()) {
        int temp = inputStack.top();
        inputStack.pop();

        while (!tempStack.empty() && tempStack.top() > temp) {
            inputStack.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(temp);
    }

    while (!tempStack.empty()) {
        inputStack.push(tempStack.top());
        tempStack.pop();
    }

    return inputStack;
}

int main() {
    stack<int> inputStack1;
    inputStack1.push(34);
    inputStack1.push(3);
    inputStack1.push(31);
    inputStack1.push(98);
    inputStack1.push(92);
    inputStack1.push(23);

    stack<int> resultStack1 = sortStack(inputStack1);

    cout << "Input: ";
    while (!inputStack1.empty()) {
        cout << inputStack1.top() << " ";
        inputStack1.pop();
    }
    cout << endl;

    cout << "Output: ";
    while (!resultStack1.empty()) {
        cout << resultStack1.top() << " ";
        resultStack1.pop();
    }
    cout << endl;

    stack<int> inputStack2;
    inputStack2.push(3);
    inputStack2.push(5);
    inputStack2.push(1);
    inputStack2.push(4);
    inputStack2.push(2);
    inputStack2.push(8);
    	
    stack<int> resultStack2 = sortStack(inputStack2);

    cout << "Input: ";
    while (!inputStack2.empty()) {
        cout << inputStack2.top() << " ";
        inputStack2.pop();
    }
    cout << endl;

    cout << "Output: ";
    while (!resultStack2.empty()) {
        cout << resultStack2.top() << " ";
        resultStack2.pop();
    }
    cout << endl;

    return 0;
}
