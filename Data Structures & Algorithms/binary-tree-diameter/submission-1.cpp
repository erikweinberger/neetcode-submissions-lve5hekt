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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        diameterHelper(root, res);
        return res;
    }

    int diameterHelper(TreeNode* root, int& res) {
        if (root == nullptr) return 0;
        int left = diameterHelper(root->left, res);
        int right = diameterHelper(root->right, res);
        res = std::max(res, left + right);
        return 1 + std::max(left, right);
    }
};
