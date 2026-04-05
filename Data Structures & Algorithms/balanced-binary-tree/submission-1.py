# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.isbalanced = True

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.dfs(root, 0)
        return self.isbalanced

    def dfs(self, root, depth):
        if root is None:
            return depth

        ldepth = self.dfs(root.left, depth + 1)
        rdepth = self.dfs(root.right, depth + 1)

        if abs(ldepth - rdepth) > 1:
            self.isbalanced = False
            return 0
        
        return max(ldepth, rdepth)
        
        
        