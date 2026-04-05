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
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        dfs(root, k, res);
        return res;
    }

private:
    int dfs(TreeNode *node, int k, int &res) {
        if (node == nullptr) return 0;

        int num_nodes_bigger_then = dfs(node->left, k, res);
        if (num_nodes_bigger_then + 1 == k) res = node->val;

        num_nodes_bigger_then += dfs(node->right, k - (num_nodes_bigger_then + 1), res);

        return num_nodes_bigger_then + 1;
    }
};
