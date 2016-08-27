class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        nums_one = 0
        while n:
            nums_one += n & 1
            n >>= 1
        return nums_one
