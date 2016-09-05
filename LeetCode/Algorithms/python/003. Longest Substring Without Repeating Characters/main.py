from collections import defaultdict


class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        last_occur = defaultdict(lambda: -1)
        sub_length = []
        max_length = 0
        for idx, val in enumerate(s):
            if idx:
                if idx - 1 - sub_length[idx - 1] >= last_occur[val]:
                    sub_length.append(sub_length[idx - 1] + 1)
                else:
                    sub_length.append(idx - last_occur[val])
                last_occur[val] = idx
            else:
                sub_length.append(1)
                last_occur[val] = idx
            max_length = max(max_length, sub_length[idx])
        return max_length
