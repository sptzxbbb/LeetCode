#! /usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        ans = []
        for i in range(num + 1):
            if i % 2 == 1:
                ans.append(ans[i - 1] + 1)
            elif i % 2 == 0:
                if i == 0:
                    ans.append(0)
                else:
                    ans.append(ans[(i - 1) // 2 + 1])
        return ans

def main():
    foo = Solution()
    print(foo.countBits(5))


if __name__ == '__main__':
    main()
