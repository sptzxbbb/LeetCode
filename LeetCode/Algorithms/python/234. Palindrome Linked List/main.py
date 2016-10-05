# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head:
            return True
        cnt = 0
        p1 = head
        while (p1):
            cnt += 1
            p1 = p1.next
        step = cnt // 2 if cnt % 2 == 0 else cnt // 2 + 1

        p2 = head
        while (step):
            p1 = p2
            p2 = p2.next
            if step == 1:
                p1.next = None
            step -= 1

        p2 = self.reverseList(p2)
        p1 = head
        while (p1 and p2):
            if p1.val != p2.val:
                return False
            p1 = p1.next
            p2 = p2.next
        return True

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
