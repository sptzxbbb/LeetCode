class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        d = set()
        while n != 1 and n not in d:
            d.add(n)
            n = self.getSum(n)
        return True if n == 1 else False

    def getSum(self, num):
        s = 0
        while num:
            num, last_digit = divmod(num, 10)
            s += last_digit**2
        return s
