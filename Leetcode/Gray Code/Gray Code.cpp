#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        if (0 == n) {
            ans.push_back(0);
            return ans;
        }
        vector<string> g = getGrayCode(n);

        int size = g.size();
        for (int i = 0; i < size; i++) {
            ans.push_back(grayToDec(g[i]));
        }
        return ans;
    }
    vector<string> getGrayCode(int n) {
        vector<string> g(pow(2, n), "");
        if (1 == n) {
            g[0] = "0";
            g[1] = "1";
            return g;
        }

        vector<string> pre = getGrayCode(n - 1);
        int size = pre.size();
        for (int i = 0; i < size; i++) {
            g[i] = ("0" + pre[i]);
            g[(size - i - 1) + size] = ("1" + pre[i]);
        }
        return g;
    }

    int grayToDec(string grayCode) {
        int sum = 0, weight = 1, size = grayCode.size();
        for (int i = size - 1; i >= 0; --i) {
            sum += (grayCode[i] - '0') * weight;
            weight *= 2;
        }
        return sum;
    }
};

int main(int argc, char *argv[]) {
    Solution k;
    k.grayCode(2);

    return 0;
}


















