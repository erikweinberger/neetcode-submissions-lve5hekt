# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:

        fast_node = head
        slow_node = head

        while fast_node is not None:
            if fast_node.next is not None:
                fast_node = fast_node.next.next
            else: return False

            slow_node = slow_node.next
            if fast_node is slow_node:
                return True

        return False

        