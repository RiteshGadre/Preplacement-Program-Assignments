// Time Complexity : O(n)
// Space Complexity : O(n)

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int countRemainingWords(const string& sequence) {
    stack<string> st;

    for (char c : sequence) {
        string word(1, c);

        if (!st.empty() && st.top() == word) {
            // Similar words, destroy both
            st.pop();
        } else {
            // Not similar, push onto stack
            st.push(word);
        }
    }

    return st.size();
}

int main() {
    string sequence1 = "ab aa aa bcd ab";
    cout << countRemainingWords(sequence1) << endl;

    string sequence2 = "tom jerry jerry tom";
    cout << countRemainingWords(sequence2) << endl;

    return 0;
}
