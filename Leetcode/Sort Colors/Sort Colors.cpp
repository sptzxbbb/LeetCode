#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // counting sort
    void sortColors1(vector<int>& nums) {
        int digit[3] = {0};
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            ++digit[nums[i]];
        }
        int count = 0;
        for (int i = 0; i < size; i++) {
            while (0 == digit[count]) {
                ++count;
            }
            nums[i] = count;
            --digit[count];
        }
        return;
    }

    // two pointers
    void sortColors(vector<int>& nums) {
        int zero = -1, two = nums.size() - 1, i = 0;
        while (i < two) {
            if (nums[i] == 0 && zero < i) {
                swap(nums[++zero], nums[i]);
            } else if (nums[i] == 2 && two > i) {
                swap(nums[--two], nums[i]);
            } else {
                ++i;
            }
        }
    }
};


int main(int argc, char *argv[]) {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    Solution k;
    k.sortColors(nums);
    return 0;
}









