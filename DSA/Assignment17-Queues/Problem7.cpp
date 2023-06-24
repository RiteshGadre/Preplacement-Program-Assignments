// Time Complexity : O(1)
// Space Complexity : O(n)

#include <queue>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class FrontMiddleBackQueue {
private:
    queue<int> front;
    queue<int> back;

    void balance() {
        if (front.size() > back.size() + 1) {
            back.push(front.front());
            front.pop();
        }
        else if (back.size() > front.size()) {
            front.push(back.front());
            back.pop();
        }
    }

public:
    FrontMiddleBackQueue() {
        
    }

    void pushFront(int val) {
        front.push(val);
        balance();
    }

    void pushMiddle(int val) {
        if (front.size() > back.size()) {
            back.push(front.front());
            front.pop();
        }
        front.push(val);
    }

    void pushBack(int val) {
        back.push(val);
        balance();
    }

    int popFront() {
        if (!front.empty()) {
            int val = front.front();
            front.pop();
            return val;
        }
        else if (!back.empty()) {
            int val = back.front();
            back.pop();
            return val;
        }
        return -1;
    }

    int popMiddle() {
        if (!front.empty()) {
            int val = front.back();
            front.pop();
            return val;
        }
        return -1;
    }

    int popBack() {
        if (!back.empty()) {
            int val = back.back();
            back.pop();
            return val;
        }
        else if (!front.empty()) {
            int val = front.back();
            front.pop();
            return val;
        }
        return -1;
    }
};



using namespace std;

int main() {
    FrontMiddleBackQueue q;

    q.pushFront(1);
    q.pushBack(2);
    q.pushMiddle(3);
    q.pushMiddle(4);

    assert(q.popFront() == 1);
    assert(q.popMiddle() == 3);
    assert(q.popMiddle() == 4);
    assert(q.popBack() == 2);
    assert(q.popFront() == -1);

    cout << "All test cases passed." << endl;

    return 0;
}
