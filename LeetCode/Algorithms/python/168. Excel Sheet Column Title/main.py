class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = ""
        base = ord('A')
        if not n:
            n -= 1
            s = "A"
        else:
            while n:
                n -= 1
                n, k = divmod(n, 26)
                s += chr(base + k)
            s = s[::-1]
        return s
