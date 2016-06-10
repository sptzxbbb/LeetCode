class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        length_s = len(s)
        length_t = len(t)
        ps = pt = 0
        while ps < length_s and pt < length_t:
            if s[ps] == t[pt]:
                ps += 1
            pt += 1
        return ps == length_s
