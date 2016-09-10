class Solution(object):
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        ans = ""
        mapping = "0123456789abcdef"
        if num:
            if num < 0:
                num += 0x100000000
            while num:
                num, digit = divmod(num, 16)
                ans = mapping[digit] + ans
        else:
            ans += "0"
        return ans
