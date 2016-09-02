from collections import deque


class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max_price, min_price = deque([]), []
        length = len(prices)
        for idx, price in enumerate(prices):
            if not idx:
                min_price.append(price)
                max_price.appendleft(prices[length - 1])
            else:
                min_price.append(min(price, min_price[-1]))
                max_price.appendleft(max(prices[length - 1 - idx], max_price[0]))
        max_profit = 0
        for i in range(length):
            max_profit = max(max_price[i] - min_price[i], max_profit)
        return max_profit
