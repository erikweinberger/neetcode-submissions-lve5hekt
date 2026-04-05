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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* resultNode = nullptr;
        lowestCommonHelper(root, p, q, resultNode);
        return resultNode;
    }

    std::pair<bool, bool> lowestCommonHelper(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode* &resultNode) {
        if (node == nullptr) return {false, false};

        std::pair<bool, bool> leftNode = lowestCommonHelper(node->left, p, q, resultNode);
        std::pair<bool, bool> rightNode = lowestCommonHelper(node->right, p, q, resultNode);

        bool thisP = node == p;
        bool thisQ = node == q;
        std::cerr << "For Node: " << node->val << " Has P been found lf,rf,tP " << leftNode.first << " , " << rightNode.first << " , " <<  thisP << " , " << "Has Q been found ls,rs,tQ " << leftNode.second << " , " << rightNode.second << " , " <<  thisQ << '\n';
        if ((leftNode.first || rightNode.first || thisP) && (thisQ || leftNode.second || rightNode.second) && resultNode == nullptr) {
            resultNode = node;
        } 

        return {(leftNode.first || rightNode.first || thisP), (thisQ || leftNode.second || rightNode.second)};

    }

};
