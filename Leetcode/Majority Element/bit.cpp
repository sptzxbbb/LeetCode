#include "iostream"
#include "vector"
#include "cstring"

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
	int bit[32];
	memset(bit, 0, sizeof(bit));
	for (int i = 0; i < nums.size(); ++i) {
	    for (int j = 0; j < 32; ++j) {
		if (nums[i] & (1 << j)) {
		    ++bit[j];
		}
	    }
	}
	int ans = 0;
	for (int i = 31; i >= 0; --i) {
	    ans <<= 1;
	    if (bit[i] > (nums.size() / 2)) {
		ans += 1;
	    }
	}
	return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<int> a;
    a.push_back(2);
    a.push_back(2);
    int k = 20;
    k >>= 2;
    cout << k << endl;
    return 0;
}
