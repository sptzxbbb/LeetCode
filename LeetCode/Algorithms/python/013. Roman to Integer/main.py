class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        mapping = {"I": 1,
                   "V": 5,
                   "X": 10,
                   "L": 50,
                   "C": 100,
                   "D": 500,
                   "M": 1000}
        length = len(s)
        res = 0
        for i in range(length):
            if length - 1 - i < length - 1 and \
            mapping[s[length - 1 - i]] < mapping[s[length - 1 - i + 1]]:
                res -= mapping[s[length - 1 - i]]
            else:
                res += mapping[s[length - 1 - i]]
        return res
