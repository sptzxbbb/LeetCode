#include <iostream>
#include <vector>
using namespace std;

// O(n)
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
// O(n)
class Solution2 {
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
            if (sum >= s) {
                minL = min(minL, right - left + 1);
                sum -= nums[left++];
            }

        }
        return minL == size + 1 ? 0 : minL;
    }
};

// O(nlogn)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        if (0 == size) {
            return 0;
        }
        vector<int> sum(size + 1, 0);
        for (int i = 1; i < size + 1; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        int minL = size + 1;
        for (int i = 1; i < size + 1; i++) {
            int diff = sum[i] - s;
            if (diff >= 0) {
                // left boundary
                int index = BinarySearch(diff, sum, 0, i - 1);
                minL = min(minL, i - index);
            }
        }
        return minL == size + 1 ? 0 : minL;
    }
    int BinarySearch(int diff, vector<int>& sum, int start, int end) {
        int index = -1, max = -1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (sum[mid] > diff) {
                end = mid - 1;
            } else {
                if (max < sum[mid]) {
                    max = sum[mid];
                    index = mid;
                }
                start = mid + 1;
            }
        }
        return index;
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
