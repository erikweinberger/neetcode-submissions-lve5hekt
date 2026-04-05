# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:

        node = head
        node2 = head

        if head.next is None:
            return None
        
        if head.next.next is None:
            if n == 1:
                head.next = None
                return head
            if n == 2:
                return head.next

        for i in range(n):
            node2 = node2.next
            if node2 is None:
                return head.next
        



        prev = None
        while node2 is not None:
            prev = node
            node = node.next
            node2 = node2.next

        prev.next = node.next

        return head
        