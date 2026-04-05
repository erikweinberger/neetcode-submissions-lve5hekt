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

struct nodeDepth {
    TreeNode *node;
    int depth;

    nodeDepth(TreeNode *n, int d) : node(n), depth(d) {}
};

class Solution {

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<vector<int>> result;
        if (root == nullptr) return result;
        std::queue<nodeDepth> nodeQueue;
        nodeQueue.push(nodeDepth {root, 0});

        while (!nodeQueue.empty()) {
            nodeDepth currNode = nodeQueue.front();
            nodeQueue.pop();

            if (currNode.depth >= 0 && currNode.depth < result.size()) {
                result[currNode.depth].push_back(currNode.node->val);
            }
            else {
                result.push_back({currNode.node->val});
            }
            if (currNode.node->left != nullptr) nodeQueue.push(nodeDepth {currNode.node->left, currNode.depth + 1});
            if (currNode.node->right != nullptr) nodeQueue.push(nodeDepth {currNode.node->right, currNode.depth + 1});
        } 
        return result;
    }
};
