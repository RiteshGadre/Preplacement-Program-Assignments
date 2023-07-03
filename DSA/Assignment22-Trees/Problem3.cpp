// Time Complexity: O(n)
// Space Complexity: O(h)

#include <iostream>
#include <vector>
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
    void printRootToLeafPaths(Node* root) {
        if (root == nullptr)
            return;

        vector<Node*> nodeStack;
        vector<string> pathStack;

        nodeStack.push_back(root);
        pathStack.push_back(to_string(root->data));

        while (!nodeStack.empty()) {
            Node* currNode = nodeStack.back();
            nodeStack.pop_back();

            string currPath = pathStack.back();
            pathStack.pop_back();

            if (currNode->left == nullptr && currNode->right == nullptr) {
                cout << currPath << endl;
            }

            if (currNode->right != nullptr) {
                nodeStack.push_back(currNode->right);
                pathStack.push_back(currPath + "->" + to_string(currNode->right->data));
            }

            if (currNode->left != nullptr) {
                nodeStack.push_back(currNode->left);
                pathStack.push_back(currPath + "->" + to_string(currNode->left->data));
            }
        }
    }
};

int main() {
    BinaryTree bt;

    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);

    cout << "Root-to-Leaf Paths:" << endl;
    bt.printRootToLeafPaths(root);

    return 0;
}
