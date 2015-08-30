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
    bool isValidBST(TreeNode* root) {
        valid(root, LONG_MIN, LONG_MAX);
    }
    bool valid(TreeNode* node, long MIN, long MAX) {
        if (node == NULL) {
            return true;
        }
        if (node->val > MIN &&
            node->val < MAX &&
            valid(node->left, MIN, node->val) &&
            valid(node->right, node->val, MAX)) {
            return true;
        } else {
            return false;
        }
    }
};