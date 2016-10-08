# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if not head:
            return None
        else:
            dumb_head = ListNode(1)
            dumb_head.next = head
            pre = dumb_head
            cur = head
            while (cur):
                if cur.val == val:
                    cur = cur.next
                    pre.next = cur
                else:
                    pre = cur
                    cur = cur.next
            return dumb_head.next
