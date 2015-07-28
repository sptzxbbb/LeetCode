#include <algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int lowestPrice[size], profit = 0;
        for (int i = 0; i < size; i++) {
            if (0 == i) {
                lowestPrice[i] = prices[i];
            } else {
                lowestPrice[i] = prices[i] >= lowestPrice[i - 1] ? lowestPrice[i - 1] : prices[i];
            }
            profit = max(profit, prices[i] - lowestPrice[i]);
        }
        return profit;
    }
};
