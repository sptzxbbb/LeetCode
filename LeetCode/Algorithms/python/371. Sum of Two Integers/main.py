class Solution(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        bit_length = 32
        mask = 1 << bit_length
        max_int = 1 << (bit_length - 1) - 1
        min_int = 1 << (bit_length - 1)

        while b:
            a, b = (a ^ b) % mask, ((a & b) << 1) % mask
        return a


class Solution2(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        MAX_INT = 0x7FFFFFFF
        MIN_INT = 0x80000000
        MASK = 0x100000000
        while b:
            a, b = (a ^ b) % MASK, ((a & b) << 1) % MASK
        return a if a <= MAX_INT else ~((a % MIN_INT) ^ MAX_INT)
