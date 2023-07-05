// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> frequencyMap;

    for (string& word : words) {
        frequencyMap[word]++;
    }

    sort(words.begin(), words.end(), [&](const string& a, const string& b) {
        if (frequencyMap[a] == frequencyMap[b]) {
            return a < b;
        } else {
            return frequencyMap[a] > frequencyMap[b];
        }
    });

    return vector<string>(words.begin(), words.begin() + k);
}

int main() {
    vector<string> words = {"apple", "banana", "apple", "orange", "banana", "apple"};
    int k = 2;
    vector<string> result = topKFrequent(words, k);

    for (string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
