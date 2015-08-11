class Solution {
public:
    // binary search
    int mySqrt(int x) {
        long i = 0, j = x / 2 + 1;
        while (i <= j) {
            long mid = (i + j) / 2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return j;
    }
};




class Solution {
public:
    // Newton's method
    int mySqrt(int x) {
        if (0 == x) {
            return 0;
        }
        double pre = 0, cur = 1;
        while (pre != cur) {
            pre = cur;
            cur = (cur + x / cur) / 2;
        }
        return (int)cur;
    }
};