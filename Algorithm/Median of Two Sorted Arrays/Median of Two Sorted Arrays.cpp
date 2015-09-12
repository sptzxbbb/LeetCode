class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) % 2 == 1) {
            return getKth(nums1, 0, m, nums2, 0, n, (m + n) / 2 + 1);
        } else {
            return (getKth(nums1, 0, m, nums2, 0, n, (m + n) / 2) + getKth(nums1, 0, m, nums2, 0, n, (m + n) / 2 + 1)) / 2.0;
        }
    }
    int getKth(vector<int>& nums1, int start1, int n, vector<int>& nums2, int start2, int m, int k) {
        if (n <= 0) {
            return nums2[start2 + k - 1];
        }
        if (m <= 0) {
            return nums1[start1 + k - 1];
        }
        if (k <= 1) {
            return min(nums1[start1], nums2[start2]);
        }

        if (nums2[start2 + m / 2] >= nums1[start1 + n / 2]) {
            if (m / 2 + n / 2 + 1 >= k) {
                return getKth(nums1, start1, n, nums2, start2, m / 2, k);
            } else {
                return getKth(nums1, start1 + n / 2 + 1, n - (n / 2 + 1), nums2, start2, m, k - (n / 2 + 1));
            }
        } else {
            if (m / 2 + n / 2 + 1 >= k) {
                return getKth(nums1, start1, n / 2, nums2, start2, m, k);
            } else {
                return getKth(nums1, start1, n, nums2, start2 + m / 2 + 1, m - (m / 2 + 1), k - (m / 2 + 1));
            }
        }
    }
};


