/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        isBalancedHelper(root, 0, balanced);
        return balanced;
    }

    int isBalancedHelper(TreeNode* node, int currDepth, bool &balanced) {
        if (node == nullptr) return currDepth;
        
        int leftDepth = isBalancedHelper(node->left, currDepth + 1, balanced);
        int rightDepth = isBalancedHelper(node->right, currDepth + 1, balanced);
        if (std::abs(leftDepth - rightDepth) > 1) balanced = false;
        return std::max(leftDepth, rightDepth);


    }
};
