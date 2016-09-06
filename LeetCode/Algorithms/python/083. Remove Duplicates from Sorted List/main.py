# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head:
            pre = head
            cur = head.next
            while cur:
                if cur.val == pre.val:
                    cur = cur.next
                    pre.next = cur
                else:
                    pre = cur
                    cur = cur.next
        return head
