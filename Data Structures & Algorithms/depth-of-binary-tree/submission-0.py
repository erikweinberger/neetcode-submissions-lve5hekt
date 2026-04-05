# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        return self.maxDeptRecur(root, 0)

    def maxDeptRecur(self, root, curr_depth):
        if root is None:
            return curr_depth
        
        return max(self.maxDeptRecur(root.left, curr_depth + 1), self.maxDeptRecur(root.right, curr_depth + 1))

        