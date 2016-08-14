class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        length = len(nums)
        p1, p2 = 0, length - 1
        cnt = 0
        while p1 <= p2:
            while p1 < length and nums[p1] != val:
                p1 += 1
            while p2 >= 0 and nums[p2] == val:
                p2 -= 1
                cnt += 1
            if p1 < p2:
                cnt += 1
                nums[p1], nums[p2] = nums[p2], nums[p1]
                p1 += 1
                p2 -= 1
        return length - cnt
