class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0 :
            return False
        div = 1
        while x // div >= 10:
            div *= 10
        while x:
            head = x // div
            tail = x % 10
            if head != tail:
                return False
            x = (x % div) / 10
            div /= 100
        return True
