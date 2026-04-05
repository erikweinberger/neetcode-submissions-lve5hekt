"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        curr = head
        new_prev = None
        new_head = None

        map_og_to_new = {}

        while curr is not None:
            new_curr = Node(x=curr.val, next=None, random=None)
            map_og_to_new[curr] = new_curr
            if new_prev:
                new_prev.next = new_curr
            else:
                new_head = new_curr
            new_prev = new_curr
            curr = curr.next

        curr = head
        while curr is not None:
            map_og_to_new[curr].random = map_og_to_new.get(curr.random, None)
            curr = curr.next
        
        return new_head



