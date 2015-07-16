class Solution {
public:
    double Power(double x, int n) {
        if (0 == n) {
            return 1;
        }
        double h = Power(x, n / 2);
        if (0 == n % 2) {
            return h * h;
        } else {
            return h * h * x;
        }
    }
    double myPow(double x, int n) {
        if (n < 0) {
            return 1.0 / Power(x, -n);
        } else {
            return Power(x, n);
        }
    }
};

