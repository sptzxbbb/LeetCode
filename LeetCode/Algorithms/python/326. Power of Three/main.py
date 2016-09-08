class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return False if n <= 0 else n == 3**round(math.log(n, 3))
