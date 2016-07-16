from collections import defaultdict


class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        d = defaultdict(lambda: 0)
        for num in nums:
            d[num] += 1
        sorted_dict = sorted(d.items(), key=lambda x: x[1], reverse=True)
        res = []
        for i in range(k):
            res.append(sorted_dict[i][0])
        return res
