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

class BinaryTree {
public:
    Node* flipBinaryTree(Node* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return root;

        Node* flippedRoot = flipBinaryTree(root->left);

        root->left->left = root->right;
        root->left->right = root;

        root->left = nullptr;
        root->right = nullptr;

        return flippedRoot;
    }

    void printTree(Node* root) {
        if (root == nullptr)
            return;

        cout << root->data << " ";
        printTree(root->left);
        printTree(root->right);
    }
};

int main() {
    BinaryTree bt;

    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);

    cout << "Original Binary Tree: ";
    bt.printTree(root);
    cout << endl;

    Node* flippedRoot = bt.flipBinaryTree(root);

    cout << "Flipped Binary Tree: ";
    bt.printTree(flippedRoot);
    cout << endl;

    return 0;
}
