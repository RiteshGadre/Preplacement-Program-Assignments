// Time Complexity: O(n)
// Space Complexity: O(n)


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorderTraversal(Node* root, Node*& prev, Node*& head) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left, prev, head);

    
    if (prev == nullptr) {
        head = root;
    } else {
        prev->right = root;
        root->left = prev;
    }

    prev = root;

    inorderTraversal(root->right, prev, head);
}

Node* convertToDoublyLinkedList(Node* root) {
    if (root == nullptr)
        return nullptr;

    Node* prev = nullptr;
    Node* head = nullptr;
    inorderTraversal(root, prev, head);

    return head;
}

void printDoublyLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

int main() {
    // Create a binary tree
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Node* head = convertToDoublyLinkedList(root);

    printDoublyLinkedList(head);

    return 0;
}
