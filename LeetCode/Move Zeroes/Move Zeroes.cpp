#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while (i < (int)nums.size() && j < (int)nums.size()) {
            // find 0
            while (i < (int)nums.size() && (int)nums[i] != 0) {
                ++i;
            }
            // find none 0
            while (j < (int)nums.size() && (int)nums[j] == 0) {
                ++j;
            }
            if (i < (int)nums.size() && j < (int)nums.size() && i < j) {
                swap(nums[i], nums[j]);
            } else {
                ++j;
            }
        }
        return;
    }
};

int main(int argc, char *argv[])
{
    int v[] = {3, 0, 1, 0, 3, 12, 15};
    vector<int> nums(v, v + 7);
    Solution k;
    k.moveZeroes(nums);
    for (int i = 0; i < (int)nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
