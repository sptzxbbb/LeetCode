class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = gas.size();
        vector<int> remain(size);
        for (int i = 0; i < size; i++) {
            remain[i] = gas[i] - cost[i];
        }
        int sum = 0, start = 0, total = 0;
        for (int i = 0; i < size; i++) {
            total += remain[i];
            sum += remain[i];
            if (sum < 0) {
                sum = 0;
                start = i + 1;
            }
        }
        if (total < 0) {
            return -1;
        } else {
            return start;
        }

    }
};