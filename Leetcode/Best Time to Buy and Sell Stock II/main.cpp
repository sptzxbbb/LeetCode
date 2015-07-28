class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<int> _prices;
        // remove adjacent duplicates
        for (int i = 0; i < size; i++) {
            if (0 == i || prices[i] != prices[i - 1]) {
                _prices.push_back(prices[i]);
            }
        }
        size = _prices.size();
        vector<int> _min, _max;
        int profit = 0;
        if (0 == size || 1 == size) {
            return profit;
        }
        if (_prices[0] < _prices[1]) {
            _min.push_back(_prices[0]);
        }
        for (int i = 1; i < size - 1; i++) {
            if (_prices[i] > _prices[i + 1] && _prices[i] > _prices[i - 1]) {
                _max.push_back(_prices[i]);
            } else if (_prices[i] < _prices[i + 1] && _prices[i] < _prices[i - 1]) {
                _min.push_back(_prices[i]);
            }
        }
        if (_prices[size - 1] > _prices[size - 2]) {
            _max.push_back(_prices[size - 1]);
        } else {
            _min.push_back(_prices[size - 1]);
        }
        size = min(_min.size(), _max.size());
        for (int i = 0; i < size; i++) {
            profit += _max[i] - _min[i];
        }
        return profit;
    }
};