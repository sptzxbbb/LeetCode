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
