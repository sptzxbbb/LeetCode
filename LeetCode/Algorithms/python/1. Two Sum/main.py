class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for idx, val in enumerate(nums):
            diff = target - val
            if diff not in d:
                d[diff] = idx
            if val in d and d[val] != idx:
                return [idx, d[val]]
