// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root, vector<int>& values) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left, values);
    values.push_back(root->value);
    inorderTraversal(root->right, values);
}

void convertToBST(TreeNode* root, vector<int>& values, int& index) {
    if (root == nullptr)
        return;

    convertToBST(root->left, values, index);
    root->value = values[index++];
    convertToBST(root->right, values, index);
}

void binaryTreeToBST(TreeNode* root) {
    vector<int> values;
    inorderTraversal(root, values);
    sort(values.begin(), values.end());
    int index = 0;
    convertToBST(root, values, index);
}

void inorderValidation(TreeNode* root, vector<int>& values, bool& isValid) {
    if (root == nullptr)
        return;

    inorderValidation(root->left, values, isValid);
    if (values.empty() || root->value <= values.back()) {
        isValid = false;
        return;
    }
    values.push_back(root->value);
    inorderValidation(root->right, values, isValid);
}

bool validateBST(TreeNode* root) {
    vector<int> values;
    bool isValid = true;
    inorderValidation(root, values, isValid);
    return isValid;
}

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    binaryTreeToBST(root);

    bool isValid = validateBST(root);
    cout << (isValid ? "Valid BST" : "Invalid BST") << endl;

    return 0;
}
