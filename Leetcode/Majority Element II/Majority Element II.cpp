class Solution {
  public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int m = 0, n = 0, count_m = 0, count_n = 0;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            if (a == m) {
                ++count_m;
            } else if (a == n) {
                ++count_n;
            } else if (count_m == 0) {
                m = a;
                count_m = 1;
            } else if (count_n == 0) {
                n = a;
                count_n = 1;
            } else {
                --count_m;
                --count_n;
            }
        }
        count_m = 0;
        count_n = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == m) {
                ++count_m;
            }
            if (nums[i] == n) {
                ++count_n;
            }
        }
        if (count_m > nums.size() / 3) {
            res.push_back(m);
        }
        if (n != m && count_n > nums.size() / 3) {
            res.push_back(n);
        }
        return res;
    }
};