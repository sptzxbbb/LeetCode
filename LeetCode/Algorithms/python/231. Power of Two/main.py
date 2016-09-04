class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0:
            return False
        last = 0
        while not last:
            last = n & 1
            n >>= 1
        return True if not n else False
