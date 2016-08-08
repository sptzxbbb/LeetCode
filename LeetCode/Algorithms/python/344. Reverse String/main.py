class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        return s[::-1]

class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = list(s)
        length = len(s)
        for i in range(0, length / 2):
            s[i], s[length - 1 - i] = s[length - 1 - i], s[i]
        return ''.join(s)

class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        length = len(s)
        if length <= 1 :
            return s
        left_s = s[:length / 2]
        right_s = s[length / 2:]
        return self.reverseString(right_s) + self.reverseString(left_s)

