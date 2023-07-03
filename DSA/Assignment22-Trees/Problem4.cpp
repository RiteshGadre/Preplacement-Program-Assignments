// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder) {
        unordered_map<int, int> indexMap;
        for (int i = 0; i < inorder.size(); ++i) {
            indexMap[inorder[i]] = i;
        }
        int preIndex = 0;
        return buildTreeHelper(preorder, indexMap, preIndex, 0, inorder.size() - 1);
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, unordered_map<int, int>& indexMap, int& preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preIndex++]);
        int inIndex = indexMap[root->val];

        root->left = buildTreeHelper(preorder, indexMap, preIndex, inStart, inIndex - 1);
        root->right = buildTreeHelper(preorder, indexMap, preIndex, inIndex + 1, inEnd);

        return root;
    }

    bool isSameTree(TreeNode* root1, vector<int>& postorder, int& postIndex) {
        if (!root1) {
            return true;
        }

        if (!isSameTree(root1->left, postorder, postIndex) || !isSameTree(root1->right, postorder, postIndex)) {
            return false;
        }

        if (root1->val != postorder[postIndex++]) {
            return false;
        }

        return true;
    }
};

bool areTraversalsSame(vector<int>& inorder, vector<int>& preorder, vector<int>& postorder) {
    Solution sol;
    TreeNode* root = sol.buildTree(inorder, preorder);

    int postIndex = 0;
    return sol.isSameTree(root, postorder, postIndex);
}

int main() {
    vector<int> inorder = {4, 2, 5, 1, 3};
    vector<int> preorder = {1, 2, 4, 5, 3};
    vector<int> postorder = {4, 5, 2, 3, 1};

    if (areTraversalsSame(inorder, preorder, postorder)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
