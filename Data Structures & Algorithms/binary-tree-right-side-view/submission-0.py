# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.right_view = []
        self.right_depth = 0

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        self.dfs_right(root, 1)
        return self.right_view

    def dfs_right(self, root, curr_depth):
        if root is None:
            return

        if curr_depth > self.right_depth:
            self.right_view.append(root.val)

        self.dfs_right(root.right, curr_depth + 1)
        self.dfs_right(root.left, curr_depth + 1)

        self.right_depth = max(self.right_depth, curr_depth)
        