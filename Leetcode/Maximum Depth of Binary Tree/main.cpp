#include "algorithm"

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
  int maxDepth(TreeNode *root) {
    if (!root) return 0;
    else return max(maxDepth(left), maxDepth(right)) + 1;
  }
};
