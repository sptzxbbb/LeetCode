#include "iostream"
#include "cmath"
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
	if (x < 0) return false;
	long long temp = x, num = 0, highest, lowest, k;
	while (temp) {  //
	    temp /= 10;
	    ++num;
	}
	temp = x;
	while (num > 1) {
	    k = (long long)(pow(10, num - 1));
	    highest = temp / k;
	    lowest = temp % 10;
	    if (highest != lowest) return false;
	    num -= 2;
	    temp = temp % k;
	    temp /= 10;
	}
	return true;
    }
};

int main(int argc, char *argv[]) {
    Solution a;
    cout << boolalpha << a.isPalindrome(-2147447412) << endl;
    return 0;
}
