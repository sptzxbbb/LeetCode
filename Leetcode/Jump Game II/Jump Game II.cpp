class Solution {
public:
    int jump(vector<int>& nums) {
        int pos = 0, next, max;
        int size = nums.size(), step = 0;
        while (pos < size - 1 && nums[pos] != 0) {
            max = -1;
            for (int i = pos + 1; i <= (pos + nums[pos]); i++) {
                if (i >= size - 1) {
                    next = size - 1;
                    break;
                } else if ((i + nums[i] >= max)) {
                    next = i;
                    max = i + nums[i];
                }
            }
            pos = next;
            ++step;
        }
        return step;
    }
};