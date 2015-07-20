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
    void flatten(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur;
        if (root != NULL) {
            s.push(root);
        }
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            if (cur->right != NULL) {
                s.push(cur->right);
            }
            if (cur->left != NULL) {
                s.push(cur->left);
            }
            cur->left = NULL;
            cur->right = (s.empty() ? NULL : s.top());
        }
        return;
    }
};