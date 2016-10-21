# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        dummy_head = ListNode(0)
        dummy_head.next = head


        i = 1
        cur = head
        pre = dummy_head
        while i < m:
            pre = cur
            cur = cur.next
            i += 1

        pre_reversed_list = pre
        reversed_tail = cur

        pre = None
        while i <= n:
            after = cur.next
            cur.next = pre

            pre = cur
            cur = after
            i += 1

        reversed_head = pre
        after_reversed_list = cur

        pre_reversed_list.next = reversed_head
        reversed_tail.next = after_reversed_list

        return dummy_head.next
