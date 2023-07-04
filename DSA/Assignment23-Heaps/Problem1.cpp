// Time Complexity: O(n)
// Space Complexity: O(h)


#include <iostream>
using namespace std;

int calculateDepth(string preorder, int& index) {
    if (index >= preorder.length())
        return -1;

    if (preorder[index] == 'l') // Leaf node
        return 0;

    index++; 
    int leftDepth = calculateDepth(preorder, index); 

    index++;
    int rightDepth = calculateDepth(preorder, index); 

    return 1 + max(leftDepth, rightDepth); 
}

int calculateDepth(string preorder) {
    int index = 0; 
    return calculateDepth(preorder, index);
}

int main() {
    string preorder = "nlnll";
    int depth = calculateDepth(preorder);
    cout << "Depth: " << depth << endl;
    return 0;
}
