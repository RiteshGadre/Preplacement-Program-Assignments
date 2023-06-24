// Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

int countStudentsUnableToEat(vector<int>& students, vector<int>& sandwiches) {
    queue<int> studentQueue;
    queue<int> sandwichStack;

    for (int student : students) {
        studentQueue.push(student);
    }
    for (int i = sandwiches.size() - 1; i >= 0; i--) {
        sandwichStack.push(sandwiches[i]);
    }

    int unableToEat = 0;

    while (!studentQueue.empty()) {
        if (studentQueue.front() == sandwichStack.front()) {
            studentQueue.pop();
            sandwichStack.pop();
            unableToEat = 0;
        } else {
            studentQueue.push(studentQueue.front());
            studentQueue.pop();
            unableToEat++;
        }

        if (unableToEat == studentQueue.size()) {
            break;
        }
    }

    return unableToEat;
}

int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};
    int unableToEat = countStudentsUnableToEat(students, sandwiches);
    cout << unableToEat << endl;

    return 0;
}
