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
    int maxPathSum(TreeNode* root) {
        int result = root->val;
        dfs(root, result);
        return result;
    }

    int dfs(TreeNode* node, int& result) {
        if (node == nullptr) return 0;

        int currVal = node->val;

        int leftPath = std::max(dfs(node->left, result), 0);
        int rightPath = std::max(dfs(node->right, result), 0);;


        result = std::max(result, currVal + leftPath + rightPath);

        return currVal + std::max(leftPath, rightPath);
    }
};
