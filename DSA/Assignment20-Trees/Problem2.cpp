// Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* constructBST(vector<int>& levelOrder) {
    if (levelOrder.empty())
        return nullptr;

    Node* root = new Node(levelOrder[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < levelOrder.size()) {
        Node* current = q.front();
        q.pop();

        int leftVal = levelOrder[i++];
        if (leftVal != -1) {
            current->left = new Node(leftVal);
            q.push(current->left);
        }

        if (i < levelOrder.size()) {
            int rightVal = levelOrder[i++];
            if (rightVal != -1) {
                current->right = new Node(rightVal);
                q.push(current->right);
            }
        }
    }

    return root;
}

void levelOrderTraversal(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left)
            q.push(current->left);

        if (current->right)
            q.push(current->right);
    }
}


int main() {
    vector<int> levelOrder = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    Node* root = constructBST(levelOrder);

    cout << "In-order traversal of the constructed BST: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
