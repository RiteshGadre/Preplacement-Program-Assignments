// Time Complexity: O(n)
// Space Complexity: O(m)

#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* next;

    Node(int val) : data(val), left(nullptr), right(nullptr), next(nullptr) {}
};

void connectNodesAtSameLevel(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        Node* prev = nullptr;

        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front();
            q.pop();

            if (prev != nullptr)
                prev->next = curr;

            prev = curr;

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}

void printNextPointers(Node* root) {
    while (root != nullptr) {
        Node* temp = root;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        root = root->left;
    }
}

int main() {
    // Create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    connectNodesAtSameLevel(root);

    cout << "Nodes at the same level: " << endl;
    printNextPointers(root);

    return 0;
}
