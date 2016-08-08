/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (!root) return false;
    int newSum = sum - root->val;
    if (newSum == 0) return true;
    if (root->left && hasPathSum(root->left, newSum)) return true;
    if (root->right && hasPathSum(root->right, newSum)) return true;
    return false;
  }
};
