class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) {
            return 0;
        }
        int maxNum = nums[0];
        int minNum = nums[0];
        for (int i = 1; i < size; i++) {
            maxNum = max(maxNum, nums[i]);
            minNum = min(minNum, nums[i]);
        }
        //int len = ceil((floor)(maxNum - minNum) / (floor)(size - 1));
        int len = (maxNum - minNum - 1) / (size - 1) + 1;
        vector<vector<int> > bucket((maxNum - minNum) / len + 1);
        for (int i = 0; i < size; i++) {
            int k = (nums[i] - minNum) / len;
            if (bucket[k].empty()) {
                bucket[k].push_back(nums[i]);
                bucket[k].push_back(nums[i]);
            } else {
                bucket[k][0] = min(bucket[k][0], nums[i]);
                bucket[k][1] = max(bucket[k][1], nums[i]);
            }
        }
        int gap = 0;
        int prev = 0;
        size = bucket.size();
        for (int i = 1; i < size; i++) {
            if (bucket[i].empty()) {
                continue;
            }
            gap = max(gap, bucket[i][0] - bucket[prev][1]);
            prev = i;
        }
        return gap;
    }
};