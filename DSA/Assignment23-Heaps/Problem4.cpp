// Time Complexity: O(n)
// Space Complexity: O(n)


#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void printBottomView(Node* root) {
    if (root == nullptr)
        return;

    map<int, int> bottomViewMap;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        pair<Node*, int> front = q.front();
        q.pop();
        Node* node = front.first;
        int hd = front.second;

        bottomViewMap[hd] = node->data;

        if (node->left)
            q.push({node->left, hd - 1});

        if (node->right)
            q.push({node->right, hd + 1});
    }

    // Print the bottom view nodes
    for (auto it = bottomViewMap.begin(); it != bottomViewMap.end(); ++it) {
        cout << it->second << " ";
    }
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    cout << "Bottom View: ";
    printBottomView(root);

    return 0;
}
