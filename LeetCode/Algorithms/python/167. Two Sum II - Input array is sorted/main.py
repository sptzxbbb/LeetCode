#! /usr/bin/env python3
# -*- coding: utf-8 -*-

import pdb


class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        for idx1, value1 in enumerate(numbers):
            if idx1 and numbers[idx1] == numbers[idx1 - 1]:
                continue
            value2 = target - value1
            if self.binarySearch(numbers[idx1 + 1:], value2):
                idx2 = numbers.index(value2, idx1 + 1)
                return [idx1 + 1, idx2 + 1]

    def binarySearch(self, numbers, target):
        length = len(numbers)
        if length == 0:
            return False

        mid = length // 2
        mid_value = numbers[mid]
        if mid_value == target:
            return True
        elif mid_value > target:
            return self.binarySearch(numbers[:mid], target)
        else:
            return self.binarySearch(numbers[mid + 1:], target)

def main():
    s = Solution()
    numbers = [2, 7, 11, 15]
    target = 17
    print(s.twoSum(numbers, target))

if __name__ == '__main__':
    main()
