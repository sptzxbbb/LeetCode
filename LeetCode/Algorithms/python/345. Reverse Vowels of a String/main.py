class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        if s:
            s = list(s)
            length = len(s)
            p1 = 0
            p2 = length - 1
            vowels = set(["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"])
            while p1 < p2:
                while s[p1] not in vowels and p1 < length - 1:
                    p1 += 1
                while s[p2] not in vowels and p2 > 0:
                    p2 -= 1
                if p1 < p2:
                    s[p1], s[p2] = s[p2], s[p1]
                    p1 += 1
                    p2 -= 1
            s = "".join(s)
        return s
