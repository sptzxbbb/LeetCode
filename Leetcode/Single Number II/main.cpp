#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit[32], size = nums.size(), ans = 0;
        memset(bit, 0, sizeof(bit));

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 32; j++) {
                bit[j] += (nums[i] >> j) & 1;
            }
        }

        for (int i = 0; i < 32; i++) {
            ans += ((bit[i] % 3) << i);
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<int> k;
    Solution a;
    k.push_back(1);
    cout << a.singleNumber(k) << endl;

    return 0;
}
