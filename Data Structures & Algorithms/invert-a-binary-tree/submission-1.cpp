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
    TreeNode* invertTree(TreeNode* root) {
        return invertTreeHelper(root);
    }

    TreeNode *invertTreeHelper(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }
        TreeNode* leftInverted = invertTreeHelper(node->left);
        TreeNode* rightInverted = invertTreeHelper(node->right);
        node->left = rightInverted;
        node->right = leftInverted;
        return node;
    }
};
