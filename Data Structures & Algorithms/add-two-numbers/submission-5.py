# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        curr_1 = l1
        curr_2 = l2

        carry = 0
        prev_node = None
        res_head = None
        while curr_1 is not None and curr_2 is not None:
            ones_spot = (curr_1.val + curr_2.val + carry) % 10
            new_node = ListNode(val=ones_spot)
            if prev_node is not None:
                prev_node.next = new_node
            else:
                print(f'here {ones_spot}')
                res_head = new_node
            carry = 1 if (curr_1.val + curr_2.val + carry) - ones_spot > 0 else 0
            prev_node = new_node

            curr_1 = curr_1.next
            curr_2 = curr_2.next
        
        while curr_1 is not None:
            ones_spot = (curr_1.val + carry) % 10
            prev_node.next = ListNode(val=ones_spot)
            carry = 1 if (curr_1.val + carry) >= 10 else 0
            prev_node = prev_node.next
            curr_1 = curr_1.next
        while curr_2 is not None:
            ones_spot = (curr_2.val + carry) % 10
            prev_node.next = ListNode(val=ones_spot)
            carry = 1 if (curr_2.val + carry) >= 10 else 0
            prev_node = prev_node.next
            curr_2 = curr_2.next

        if carry > 0:
            prev_node.next = ListNode(val=carry)

        return res_head

        
        