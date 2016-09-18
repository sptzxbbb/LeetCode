#! /usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        non_zero_count = 0
        for idx, val in enumerate(nums):
            if val:
                nums[non_zero_count] = nums[idx]
                non_zero_count += 1

        # nums[zero_count:] =
        nums[non_zero_count:] = [0 for x in range(len(nums) - non_zero_count)]
        return

def main():
    s = Solution()
    nums = []
    s.moveZeroes(nums)
    print(nums)

if __name__ == '__main__':
    main()
