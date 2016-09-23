#! /usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums1 = sorted(nums1)
        nums2 = sorted(nums2)
        res = []
        p1, p2 = 0, 0
        len1, len2 = len(nums1), len(nums2)
        while(p1 < len1 and p2 < len2):
            num1 = nums1[p1]
            num2 = nums2[p2]
            if num1 == num2:
                res.append(num1)
                while p1 < len1 and nums1[p1] == num1:
                    p1 += 1
                while p2 < len2 and nums2[p2] == num2 :
                    p2 += 1
            elif num1 > num2:
                p2 += 1
            else:
                p1 += 1
        return res


if __name__ == '__main__':
    s = Solution()
    print(s.intersection([1], [1, 2]))
