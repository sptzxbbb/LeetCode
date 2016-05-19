struct node {
    int value;
    int index;
    node(int _value, int _index) : value(_value), index(_index) {}
};

bool cmp(const node &left, const node &right) {
    return left.value < right.value;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<node> ele;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            ele.push_back(node(nums[i], i));
        }
        sort(ele.begin(), ele.end(), cmp);
        int left = 0, right = size - 1;
        vector<int> result;
        while (left < right) {
            int sum = ele[left].value + ele[right].value;
            if (target == sum) {
                result.push_back(ele[left].index + 1);
                result.push_back(ele[right].index + 1);
                sort(result.begin(), result.end());
                break;
            } else if (sum > target) {
                --right;
            } else {
                ++left;
            }
        }
        return result;
    }
};