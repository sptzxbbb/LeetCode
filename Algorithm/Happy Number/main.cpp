#include "iostream"
#include "cstring"
#include "vector"
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        bool exist[811];
	vector<int> b;
	int temp;
	b.push_back(111);
        memset(exist, 0, sizeof(exist));
        do {
            temp = sum(n);
            if (1 == temp) {
                return true;
            } else {
                if (false == exist[temp]) {
                    n = temp;
                    exist[n] = true;
                } else {
                    return false;
                }
            }
        } while (1);
    }
        
    int sum(int n) {
        int ans = 0;
        while (n) {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution k;
    vector<int> a;
    a.push_back(15);
    cout << k.isHappy(2) << endl; 
    return 0;
}
