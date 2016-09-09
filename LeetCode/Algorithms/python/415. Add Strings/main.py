class Solution(object):
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        length1, length2 = len(num1), len(num2)
        num1, num2 = list(map(int, num1)), list(map(int, num2))

        # make num1 the longer string
        if length1 < length2:
            num1, num2 = num2, num1
            length1, length2 = length2, length1
        carry = 0
        for idx in range(length1):
            num1[length1 - 1 - idx] += carry
            if idx < length2:
                num1[length1 - 1 - idx] += num2[length2 - 1 - idx]
            carry, num1[length1 - 1 - idx] = divmod(num1[length1 - 1 - idx],
                                                    10)
        if carry:
            num1.insert(0, 1)
            carry = 0

        num1 = list(map(str, num1))
        ans = ''.join(num1)
        return ans
