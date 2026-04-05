# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        carry = 0
        dummy_head = ListNode()
        prev = dummy_head
        while l1 is not None or l2 is not None or carry != 0:
            val1 = l1.val if l1 is not None else 0
            val2 = l2.val if l2 is not None else 0

            sum = val1 + val2 + carry
            new_val = sum % 10
            carry = sum // 10

            prev.next = ListNode(val=new_val)
            prev = prev.next

            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        return dummy_head.next

        
        