# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
import gc


class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        length1 = self.getListLen(headA)
        length2 = self.getListLen(headB)
        # Make List A the longer list
        if length1 < length2:
            headA, headB = headB, headA
        # Trim the longer part
        p1, p2 = headA, headB
        diff = abs(length1 - length2)
        while (diff):
            diff -= 1
            p1 = p1.next

        while (p1 != p2):
            p1 = p1.next
            p2 = p2.next

        return p2

    def getListLen(self, head):
        length = 0
        p1 = head
        while (p1):
            length += 1
            p1 = p1.next
        gc.collect()
        return length

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def getIntersectionNode(self, headA, headB):
        A, B = headA, headB
        while A != B:
            A = A.next if A else headB
            B = B.next if B else headA
        gc.collect()
        return A
