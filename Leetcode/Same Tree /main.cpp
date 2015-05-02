/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursive
class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
      // both empty node, same
    if (!p && !q) return true;
    // only one empty node, distinct
    if (p && !q || !p && q) return false;
    // both subtrees and val are the same
    if (isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right)
        && p->val == q->val)
      return true;
    // at least one of the three elements are distinct
    return false;
  }
};
