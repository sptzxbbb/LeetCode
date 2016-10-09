class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        res = 0
        length = len(s)
        for idx, val in enumerate(s):
            res += (ord(val) - ord("A") + 1) * 26**(length - 1 - idx)
        return res
