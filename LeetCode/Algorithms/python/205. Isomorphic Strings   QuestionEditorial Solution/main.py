class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        lengthS = len(s)
        lengthT = len(t)
        if lengthS != lengthT:
            return False
        d = {}
        mapped_ch = set()
        for i in range(lengthS):
            if s[i] in d:
                if d[s[i]] != t[i]:
                    return False
            else:
                if t[i] not in mapped_ch:
                    d[s[i]] = t[i]
                    mapped_ch.add(t[i])
                else:
                    return False
        return True
