class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        profit = 0
        length = len(prices)
        for idx, price in enumerate(prices):

                profit +=  prices[idx + 1] - price
        return profit
