class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        profit = []
        for idx, val in enumerate(nums):
            if idx == 0:
                profit.append(val)
            elif idx == 1:
                profit.append(max(nums[idx - 1], nums[idx]))
            else:
                profit.append(max(profit[-1], profit[-2] + val))
        return profit[-1]
