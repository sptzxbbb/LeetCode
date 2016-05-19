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
    vector<int> inorderTraversal(TreeNode* root) {
        in(root);
        return tree;
    }
    void in(TreeNode* root) {
        if (root != NULL) {
            if (root->left != NULL) in(root->left);
            tree.push_back(root->val);
            if (root->right != NULL) in(root->right);
        }
    }
private:
    vector<int> tree;
};

class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> order;
        vector<int> ans;
        TreeNode* p = root;
        while (p != NULL || !order.empty()) {
            if (p != NULL) {
                order.push(p);
                p = p->left;
            } else {
                p = order.top();
                order.pop();
                ans.push_back(p->val);
                p = p->right;
            }
        }
        return ans;
    }
};
