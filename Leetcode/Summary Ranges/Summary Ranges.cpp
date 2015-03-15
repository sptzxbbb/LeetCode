class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ele;
        int size = nums.size();
        if (0 == size) {
            return ele;
        }
        int left;
        string s;
        for (int i = 0; i < size; ++i) {
            if (0 == i) {
                left = i;
                s = intToString(nums[left]);
            } else {
                if (nums[i] != nums[i - 1] + 1) {
                    if (i - 1 != left) {
                        s += "->" + intToString(nums[i - 1]);
                    }
                    ele.push_back(s);
                    s.clear();
                    left = i;
                    s = intToString(nums[left]);
                }
            }
            if (size - 1 == i) {
                if (size > 1 && nums[i] == nums[i - 1] + 1) {
                    s += "->" + intToString(nums[i]);
                }
                ele.push_back(s);
            }
        }
        return ele;
    }

    string intToString(int n) {
        char t[256];
        string s;
        sprintf(t, "%d", n);
        s = t;
        return s;
    }
};



