# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return None
        else:
            p1 = None
            p2 = head
            while (p2):
                temp = p2.next
                p2.next = p1

                p1 = p2
                p2 = temp
            return p1
