// Time Complexity: O(h)
// Space Complexity: O(h)

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};
int findDistance(Node* root, int key1, int key2) {
    if (root == nullptr)
        return 0;

    if (root->key > key1 && root->key > key2)
        return findDistance(root->left, key1, key2);

    if (root->key < key1 && root->key < key2)
        return findDistance(root->right, key1, key2);

    int distance1 = findDistanceFromNode(root, key1);
    int distance2 = findDistanceFromNode(root, key2);

    if (distance1 != -1 && distance2 != -1)
        return distance1 + distance2 - 2; // Subtract 2 to account for the common ancestor

    return -1;
}


int findDistanceFromNode(Node* node, int key) {
    if (node == nullptr)
        return -1;

    if (node->key == key)
        return 0;

    if (node->key > key)
        return findDistanceFromNode(node->left, key);
    else
        return findDistanceFromNode(node->right, key);

    return -1;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    root->left->right->left = new Node(3);

    int key1 = 3;
    int key2 = 8;
    int distance = findDistance(root, key1, key2);
    cout << "Distance between " << key1 << " and " << key2 << " is " << distance << endl;

    return 0;
}
