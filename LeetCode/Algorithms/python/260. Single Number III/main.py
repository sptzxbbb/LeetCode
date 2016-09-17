#! /usr/bin/env python3
# -*- coding: utf-8 -*-

from functools import reduce

class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        xor = reduce(lambda x, y: x ^ y, nums)
        lowbit = xor & -xor
        a = b = 0
        for e in nums:
            if e & lowbit:
                a ^= e
            else:
                b ^= e
        return [a, b]


def main():
    s = Solution()
    ans = s.singleNumber([2,1,2,3,4,1])
    print(ans)




if __name__ == '__main__':
    main()
