// Time Complexity : O(nlogn)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(), deck.end());
    queue<int> indices;

    for (int i = 0; i < deck.size(); ++i) {
        indices.push(i);
    }

    vector<int> result(deck.size());

    for (int card : deck) {
        result[indices.front()] = card;
        indices.pop();

        if (!indices.empty()) {
            indices.push(indices.front());
            indices.pop();
        }
    }

    return result;
}


int main(){
	vector<int> deck = {17,13,11,2,3,5,7};
	auto ans = deckRevealedIncreasing(deck);
	for(auto element : ans)
		cout << element << " ";
}