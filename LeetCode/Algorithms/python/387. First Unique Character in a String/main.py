from collections import defaultdict


class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = defaultdict(lambda: 0)
        for c in s:
            d[c] += 1
        for idx, c in enumerate(s):
            if d[c] == 1:
                return idx
        return -1
