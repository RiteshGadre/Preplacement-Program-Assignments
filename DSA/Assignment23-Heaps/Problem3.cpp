// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
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

void printRightViewUtil(Node* root, int level, int& maxLevel) {
    if (root == nullptr)
        return;

    if (level > maxLevel) {
        cout << root->data << " ";
        maxLevel = level;
    }

    printRightViewUtil(root->right, level + 1, maxLevel);
    printRightViewUtil(root->left, level + 1, maxLevel);
}

void printRightView(Node* root) {
    int maxLevel = -1;
    printRightViewUtil(root, 0, maxLevel);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);

    cout << "Right View: ";
    printRightView(root);

    return 0;
}
