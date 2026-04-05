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
    int goodNodes(TreeNode* root) {
        int res = 0;
        goodNodesHelper(root, -101, res);
        return res;
    }

    void goodNodesHelper(TreeNode *node, int currMax, int &res) {
        if (node == nullptr) return;

        if (node->val >= currMax) {
            res++;
            currMax = node->val;
        }

        goodNodesHelper(node->left, currMax, res);
        goodNodesHelper(node->right, currMax, res);

    }
};
