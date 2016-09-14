class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        length1 = len(s)
        length2 = len(t)
        if length1 != length2:
            return False
        else:
            d1, d2 = {}, {}
            for c in s:
                if c not in d1:
                    d1[c] = 1
                else:
                    d1[c] += 1
            for c in t:
                if c not in d2:
                    d2[c] = 1
                else:
                    d2[c] += 1
            for c in s:
                if c not in d2 or d1[c] != d2[c]:
                    return False
            return True
