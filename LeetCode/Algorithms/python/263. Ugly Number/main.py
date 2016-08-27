#! /usr/bin/env python3
# -*- coding: utf-8 -*-

import math


class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False
        if num == 1:
            return True
        factors = [2, 3, 5]
        for f in factors:
            num = self.divisible(num, f)
        return True if num == 1 else False

    def divisible(self, num, factor):
        """
        if num si divisible by factor**k, return quotient
        Otherwise, return num itself
        """
        while True:
            if num % factor:
                break
            else:
                num = num / factor
        return num

if __name__ == '__main__':
    s = Solution()
    print(s.isUgly(1))
