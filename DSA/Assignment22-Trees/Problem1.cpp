// Time Complexity: O(n)
// Space Complexity: O(h)

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

Node* prevNode = nullptr;

Node* binaryTreeToDLL(Node* root) {
    if (root == nullptr)
        return nullptr;

    Node* head = binaryTreeToDLL(root->left);

    if (prevNode == nullptr)
        head = root;
    else {
        root->left = prevNode;
        prevNode->right = root;
    }

    prevNode = root;

    binaryTreeToDLL(root->right);

    return head;
}

void printDLL(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

int main() {
    // Create a sample binary tree
    Node* root = new Node();
    root->data = 4;
    root->left = new Node();
    root->left->data = 2;
    root->left->left = new Node();
    root->left->left->data = 1;
    root->left->right = new Node();
    root->left->right->data = 3;
    root->right = new Node();
    root->right->data = 5;

    Node* head = binaryTreeToDLL(root);
    printDLL(head);

    return 0;
}
