class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size < 2) {
            return 0;
        }

        int minPrice = prices[0], left[size];
        int maxProfit = 0;
        left[0] = 0;
        for (int i = 1; i < size; i++) {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
            left[i] = maxProfit;
        }
        maxProfit = 0;
        int maxPrice = prices[size - 1], ans = left[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            maxProfit = max(maxProfit, maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
            ans = max(ans, left[i] + maxProfit);
        }
        return ans;
    }
};