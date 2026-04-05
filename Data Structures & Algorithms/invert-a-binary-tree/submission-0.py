# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        return self.invertTreeRecur(root)

    def invertTreeRecur(self, root):
        if root is None:
            return
        
        self.invertTreeRecur(root.right)
        self.invertTreeRecur(root.left)
        temp = root.right
        root.right = root.left
        root.left = temp

        return root

        
        