// Time Complexity : O(k)
// Space Complexity : O(k)

#include <iostream>
#include <cassert>
#include <deque>
using namespace std;

class DataStream {
private:
    int value;
    int k;
    deque<int> stream;

public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
    }

    bool consec(int num) {
        stream.push_back(num);

        if (stream.size() < k)
            return false;

        if (stream.size() > k)
            stream.pop_front();

        for (int i = 0; i < k; i++) {
            if (stream[i] != value)
                return false;
        }

        return true;
    }
};


int main() {
    DataStream dataStream(4, 3);

    assert(dataStream.consec(4) == false);
    assert(dataStream.consec(4) == false);
    assert(dataStream.consec(4) == true);
    assert(dataStream.consec(3) == false);

    cout << "All test cases passed." << std::endl;

    return 0;
}
