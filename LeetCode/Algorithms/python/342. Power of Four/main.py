class Solution(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False
        exp = round(math.log(num, 4))
        return True if num == 4**exp else False
