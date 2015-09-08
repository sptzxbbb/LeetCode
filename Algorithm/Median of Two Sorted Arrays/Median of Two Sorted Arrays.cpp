class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) % 2 == 1) {

        } else {

        }
    }
    int getKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
        if (end1 <= 0) {
            return nums2[k - 1];
        }
        if (end2 <= 0) {
            return nums1[k - 1];
        }
        if (k <= 1) {
            return min(nums1[0], nums2[0]);
        }
        int m = (start1 + end1) / 2, m = (start2 + end2) / 2;
        if (nums1[m] >= nums2[n]) {
            
        } else {
            
        }

    }
};


