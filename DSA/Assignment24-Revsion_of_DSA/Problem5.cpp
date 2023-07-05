// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
using namespace std;

int nthUglyNumber(int n) {
    vector<int> uglyNumbers(n);
    uglyNumbers[0] = 1; // First ugly number is 1

    int idx2 = 0, idx3 = 0, idx5 = 0; // Pointers for 2, 3, and 5 multiples
    int nextMultipleOf2 = 2, nextMultipleOf3 = 3, nextMultipleOf5 = 5;

    for (int i = 1; i < n; i++) {
        // Find the next ugly number by choosing the smallest among the multiples of 2, 3, and 5
        int nextUglyNumber = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
        uglyNumbers[i] = nextUglyNumber;

        // Update the pointers and next multiples
        if (nextUglyNumber == nextMultipleOf2) {
            idx2++;
            nextMultipleOf2 = uglyNumbers[idx2] * 2;
        }
        if (nextUglyNumber == nextMultipleOf3) {
            idx3++;
            nextMultipleOf3 = uglyNumbers[idx3] * 3;
        }
        if (nextUglyNumber == nextMultipleOf5) {
            idx5++;
            nextMultipleOf5 = uglyNumbers[idx5] * 5;
        }
    }

    return uglyNumbers[n - 1]; // Return the nth ugly number
}

int main() {
    int n = 10;
    int result = nthUglyNumber(n);
    cout << "The " << n << "th ugly number is: " << result << endl;
    return 0;
}
