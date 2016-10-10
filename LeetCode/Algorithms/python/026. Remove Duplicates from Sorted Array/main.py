class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length <= 1:
            return length
        else:
            p1, p2 = 1, 1
            pre = nums[0]
            while p2 < length:
                if nums[p2] != pre:
                    nums[p1] = nums[p2]
                    pre = nums[p2]
                    p1 += 1
                p2 += 1
            return p1
