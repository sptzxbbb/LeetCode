class Solution {
public:
    int rob(vector<int> &num) {
        int n = num.size(), value[n];
        for (int i = 0; i < num.size(); ++i) {
            if (0 == i) value[i] = num[i];
            else if (1 == i) value[i] = max(value[i - 1], num[i]);
            else value[i] = max(value[i - 1], value[i - 2] + num[i]);
        }
        return value[n - 1];
    }
};
