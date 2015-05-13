#include <vector>
#include <iostream>
using namespace std;

typedef enum {
    lowest,
    middle,
    highest
} my_price;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size(), profit = 0, value;
        my_price trend[size];
        bool hold = false;
        // no transaction available
        if (size <= 1) {
            return profit;
        }
        // deal with the beginning and the end
        if (size > 1) {
            if (prices[1] > prices[0]) {
                trend[0] = lowest;
            } else if (prices[1] < prices[0]) {
                trend[0] = highest;
            } else {
                trend[0] = middle;
            }
            if (prices[size - 1] > prices[size - 2]) {
                trend[size - 1] = highest;
            } else if (prices[size - 1] < prices[size - 2]) {
                // suppose to be a day with lowest price,but we can't sell it in the futrue, so set it middle
                trend[size - 1] = middle;
            } else {
                trend[size - 1] = middle;
            }
        }
        for (int i = 0; i < size; i++) {
            // if it's a extermal point
            if (i > 0 && i < size - 1) {
                if (prices[i] == prices[i - 1] && prices[i] == prices[i + 1]) {
                    trend[i] = middle;
                } else if (prices[i] >= prices[i - 1] && prices[i] >= prices[i + 1]) {
                    trend[i] = highest;
                } else if (prices[i] <= prices[i - 1] && prices[i] <= prices[i + 1]) {
                    trend[i] = lowest;
                } else {
                    trend[i] = middle;
                }
            }
            // transaction
            if (false == hold && lowest == trend[i]) {
                hold = true;
                value = prices[i];
            } else if (true == hold && highest == trend[i]) {
                hold = false;
                profit += prices[i] - value;
            }
        }
        return profit;
    }
};

int main(int argc, char *argv[]) {
    int a[]= {2,9,2,3,8,1,5,8,4,3,6,4,4};
    vector<int> price(a, a + 13);
    Solution k;
    cout << k.maxProfit(price) << endl;
    return 0;
}
