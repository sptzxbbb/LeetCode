class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = 0
        num = None
        for n in nums:
            if not cnt:
                cnt = 1
                num = n
            else:
                if n == num:
                    cnt += 1
                else:
                    cnt -= 1
        return num
