class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int size = nums.size();
        int i = 0;
        vector<int> res;
        while (i < size) {
            if (q.size() && i - q.front() > k - 1) {
                q.pop_front();
            }
            // deal with ith element
            while (q.size() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1) {
                res.push_back(nums[q.front()]);
            }
            ++i;
        }
        return res;
    }
};

