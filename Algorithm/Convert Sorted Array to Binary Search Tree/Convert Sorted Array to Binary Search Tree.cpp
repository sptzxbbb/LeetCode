/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return NULL;
        }
        return generate(nums, 0, nums.size() - 1);
    }
    TreeNode* generate(vector<int>& nums, int start, int end) {
        int mid = (start + end) / 2;
        TreeNode* p = new TreeNode(nums[mid]);
        if (start < end) {
            if (start <= mid - 1)
                p->left = generate(nums, start, mid - 1);
            if (mid + 1 <= end)
                p->right = generate(nums, mid + 1, end);
        }
        return p;
    }
};