from functools import reduce


class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        L = []
        if n:
            for k in range(1, n + 1):
                if k == 1:
                    L.append(10)
                elif k == 2:
                    L.append(81)
                else:
                    L.append(L[-1] * (9 - k + 2))
        else:
            L.append(1)
        return sum(L)
