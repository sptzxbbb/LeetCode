#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0;
        int size = nums.size();
        if (0 == size) {
            return 0;
        }
        int sum = nums[0], minL = size + 1;
        do {
            if (sum < s) {
                sum += nums[++right];
            } else {
                sum -= nums[left++];
                if (left > right) {
                    minL = 1;
                    break;
                }
            }
            if (sum >= s) {
                minL = min(minL, right - left + 1);
            }
        } while (!(right == size - 1 && (sum < s || left == size - 1)));
        return minL == size + 1 ? 0 : minL;
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        if (0 == size) {
            return 0;
        }
        int left = 0, right = 0, sum = nums[0], minL = size + 1;
        while (right < size) {
            while (sum < s && right < size) sum += nums[++right];
            // while (sum >= s && left <= right) {
            //     minL = min(minL, right - left + 1);
            //     sum -= nums[left++];
            // }
            while (sum >= s) {
                minL = min(minL, right - left + 1);
                sum -= nums[left++];
            }

        }
        return minL == size + 1 ? 0 : minL;
    }
};

int main(int argc, char *argv[])
{
    int a[] = {5,1,3 ,5,10,7,4,9,2,8};
    vector<int> v(&a[0], &a[9]);
    Solution k;
    cout << k.minSubArrayLen(15, v) << endl;
    return 0;
}
