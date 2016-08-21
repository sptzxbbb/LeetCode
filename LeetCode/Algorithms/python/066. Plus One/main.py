class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        length = len(digits)
        carry = 1
        for idx, digit in enumerate(digits):
            digits[length - 1 - idx] += carry
            carry, digits[length - 1 - idx] = divmod(digits[length - 1 - idx], 10)
        if carry:
            digits.insert(0, 1)
        return digits
