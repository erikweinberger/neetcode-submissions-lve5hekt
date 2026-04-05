# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        middle = self.findLength(head) // 2

        if middle < 1:
            return None

        node = head
        prev = None
        for i in range(middle):
            prev = node
            node = node.next
        prev.next = None

        head2 = self.reverseList(node)
        node = head2
        while node is not None:
            node = node.next


        head1 = head
        curr = head1

        i = True
        while head1 is not None and head2 is not None:

            if i:
                head1 = curr.next
                curr.next = head2
                head2 = head2.next
            else:
                head2 = curr.next
                curr.next = head1
                head1 = head1.next
            curr = curr.next
            i = not i
        
        if head1 is not None:
            curr.next = head1
        elif head2 is not None:
            curr.next = head2





    

    def findLength(self, head: Optional[ListNode]) -> int:
        node = head
        i = 0
        while node is not None:
            i += 1
            node = node.next

        return i


    def reverseList(self, head: Optional[ListNode]) -> ListNode:
        curr = head
        prev = None

        while curr is not None:
            nexter = curr.next
            curr.next = prev
            prev = curr
            curr = nexter
        
        return prev


        