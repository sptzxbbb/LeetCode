class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        cur, pre = 0, 0
        for t in range(1, n + 1):
            if t == 1:
                cur = 1
            elif t == 2:
                pre = cur
                cur = 2
            else:
                cur, pre = cur + pre, cur
        return cur
