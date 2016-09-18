#! /usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = []
        for idx, val in enumerate(nums):
            if idx == 0:
                ans.append(1)
            else:
                ans.append(ans[idx - 1] * nums[idx - 1])


        length = len(nums)
        for idx, val in enumerate(reversed(nums)):
            if idx == 0:
                right_product = 1
            else:
                right_product *= nums[length - 1 - (idx - 1)]
                ans[length - 1 - idx] *= right_product
        return ans


def main():
    s = Solution()
    nums = [1, 2, 3, 4, 5]
    ans = s.productExceptSelf(nums)
    print(ans)

if __name__ == '__main__':
    main()
