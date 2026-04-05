# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.diameter = 0

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.dfs(root, 0)
        return self.diameter

    def dfs(self, root, curr_depth):
        if root is None:
            return curr_depth

        left_d = self.dfs(root.left, curr_depth)
        right_d = self.dfs(root.right, curr_depth)

        self.diameter = max(self.diameter, left_d + right_d)
        print(self.diameter)

        return 1 + max(left_d, right_d)



