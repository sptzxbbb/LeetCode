# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution2(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        s1, s2 = self.getNum(l1), self.getNum(l2)
        s = s1 + s2
        if not s:
            ans = ListNode(0)
        else:
            dumb_head = ListNode(-1)
            pre = dumb_head
            while s:
                s, last_digit = divmod(s, 10)
                cur = ListNode(last_digit)
                pre.next = cur
                pre = cur
            ans = dumb_head.next
        return ans

    def getNum(self, head):
        p = head
        s = ""
        while p:
            s += str(p.val)
            p = p.next
        s = s[::-1]
        return int(s)

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dumb_head = ListNode(-1)
        pre = dumb_head
        p1, p2 = l1, l2
        s, carry = 0, 0
        while p1 or p2:
            s = 0
            if p1:
                s += p1.val
                p1 = p1.next
            if p2:
                s += p2.val
                p2 = p2.next
            s += carry
            carry, s = divmod(s, 10)
            cur = ListNode(s)
            pre.next = cur
            pre = cur
        if carry:
            pre.next = ListNode(carry)

        return dumb_head.next
