class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        total_s = 0
        for c in s:
            total_s += ord(c)

        total_t = 0
        for c in t:
            total_t += ord(c)

        ans = chr(total_t - total_s)
        return ans
