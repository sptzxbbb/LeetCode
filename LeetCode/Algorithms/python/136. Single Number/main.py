#! /usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        for e in nums:
            ans = ans ^ e
        return ans


def main():
    nums = [1, 2, 3, 4, 3, 2, 1]
    s = Solution()
    print(s.singleNumber(nums))


if __name__ == '__main__':
    main()
