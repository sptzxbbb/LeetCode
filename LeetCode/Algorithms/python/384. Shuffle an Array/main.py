#! /usr/bin/env python3
# -*- coding: utf-8 -*-

import random

class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        :type size: int
        """
        self.original = nums[:]
        self.current = nums[:]

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        self.current = self.original[:]
        return self.current

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        #       random.shuffle(self.current)
        self.current = sorted(self.current, key=lambda x: random.random())
        return self.current

# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()

def main():
    s = Solution([1, 2, 3, 4])
    print(s.shuffle())
    print(s.reset())
if __name__ == '__main__':
    main()
