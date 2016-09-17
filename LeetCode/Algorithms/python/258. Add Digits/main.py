class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        l = [9, 1, 2, 3, 4, 5, 6, 7, 8]
        return l[num % 9] if num != 0 else 0
