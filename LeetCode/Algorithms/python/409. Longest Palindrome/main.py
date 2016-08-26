class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = {}
        for e in s:
            if e not in d:
                d[e] = 1
            else:
                d[e] += 1
        odd = False
        val = d.values()
        length = 0
        for v in val:
            if v % 2 == 1:
                length += v - 1
                odd = True
            else:
                length += v
        length += int(odd)
        return length
