class Solution {
public:
    int addDigits(int num) {
        int ans = num - 9 * ((num - 1) / 9);
        return ans;
    }
};