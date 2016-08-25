# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        left, right = 1, n
        pivot = (left + right) // 2
        while True:
            res = guess(pivot)
            if not res:
                return pivot
            elif res == 1:
                left = pivot + 1
            else:
                right = pivot - 1
            pivot = (left + right) // 2
