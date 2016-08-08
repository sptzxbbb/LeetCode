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
  bool isSymmetric(TreeNode *root) {
    if (!root) return true;

    travel1(root->left);
    travel2(root->right);

    if (left.size() != right.size()) return false;

    for (int i = 0; i < left.size(); ++i) {
      if (left[i] && !right[i]) return false;
      if (!left[i] && right[i]) return false;
      if (left[i] && right[i] && left[i]->val != right[i]->val) return false;
    }
    return true;
  }

  void travel1(TreeNode* l) {
    if (!l) {
      left.push_back(NULL);
      return;
    }
    travel1(l->left);
    travel1(l->right);
    left.push_back(l);
    return;
  }

  void travel2(TreeNode* r) {
    if (!r) {
      right.push_back(NULL);
      return;
    }
    travel2(r->right);
    travel2(r->left);
    right.push_back(r);
    return;
  }

private:
  vector<TreeNode*> left, right;
};
