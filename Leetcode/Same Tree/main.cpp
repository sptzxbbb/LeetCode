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


class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
      if (!p && !q) {
          return true;
      } else if ((!p && q) || (p && !q)) {
          return false;
      }
      p_list.push_back(p);
      q_list.push_back(q);
      TreeNode *p_node, *q_node;
      while (!p_list.empty()) {
          p_node = p_list.front();
          q_node = q_list.front();
          p_list.pop_front();
          q_list.pop_front();

          if ((p_node->val != q_node->val) ||
              (p_node->left && !q_node->left) ||
              (p_node->right && !q_node->right) ||
              (!p_node->left && q_node->left) ||
              (!p_node->right && q_node->right)
              ) {
              return false;
          }

          if (p_node->left) {
              p_list.push_back(p_node->left);
          }
          if (p_node->right) {
              p_list.push_back(p_node->right);
          }
          if (q_node->left) {
              q_list.push_back(q_node->left);
          }
          if (q_node->right) {
              q_list.push_back(q_node->right);
          }

      }
      return true;
  }
private:
    list<TreeNode*> p_list, q_list;
};
