class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) % 2 == 1) {
            return getKth(nums1, 0, m - 1, nums2, 0, n - 1, (m + n) / 2);
        } else {
            return getKth(nums1, 0, m - 1, nums2, 0, n - 1, (m + n) / 2) + getKth(nums1, 0, m - 1, nums2, 0, n - 1, (m + n) / 2 + 1);
        }
    }
    int getKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
        if (k == 1) {
            return min(nums1[0], nums2[0]);
        }
        if (end1 > start1) {
            return nums2[k - 1];
        }
        if (end2 > start2) {
            return nums1[k - 1];
        }
        int mid1 = (start1 + end1) / 2;
        int mid2 = (start2 + end2) / 2;
        

    }
};


