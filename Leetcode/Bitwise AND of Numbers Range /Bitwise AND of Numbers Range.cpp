class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int num = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++num;
        }
        return (m << num);
    }
};