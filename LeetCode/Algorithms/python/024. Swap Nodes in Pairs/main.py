# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        p1 = head
        p2 = head.next
        dummy_head = ListNode(-1)
        dummy_head.next = p1
        pre = dummy_head
        while p1 and p2:
            after = p2.next

            pre.next = p2
            p2.next = p1
            p1.next = after

            pre = p1
            p1 = after
            p2 = p1.next if p1 else None
        return dummy_head.next
