class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        profit = 0
        length = len(prices)
        for idx, price in enumerate(prices):
            if idx < length - 1 and price < prices[idx + 1]:
                profit += prices[idx + 1] - price
        return profit
