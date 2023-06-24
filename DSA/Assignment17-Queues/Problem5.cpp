// Time Complexity : O(n*k)
// Space Complexity : O(n)

#include <queue>

int findTheWinner(int n, int k) {
    std::queue<int> friends;
    for (int i = 1; i <= n; ++i) {
        friends.push(i);
    }

    while (friends.size() > 1) {
        for (int i = 1; i < k; ++i) {
            friends.push(friends.front());
            friends.pop();
        }
        friends.pop();
    }

    return friends.front();
}
