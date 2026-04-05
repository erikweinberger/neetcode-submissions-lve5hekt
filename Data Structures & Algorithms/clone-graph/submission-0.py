"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def __init__(self):
        self.result = {}


    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None:
            return
        self.dfs_copy(node)
        return self.result[node]
        
    def dfs_copy(self, node):
        if node is None:
            return

        if node not in self.result.keys():
            self.result[node] = Node(node.val)

        for neigh in node.neighbors:
            if neigh not in self.result.keys():
                neigh_copy = Node(neigh.val)
                self.result[node].neighbors.append(neigh_copy)
                self.result[neigh] = neigh_copy
                self.dfs_copy(neigh)
            else:
                self.result[node].neighbors.append(self.result[neigh])

            



        