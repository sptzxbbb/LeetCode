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
    vector<int> preorderTraversal(TreeNode* root) {
        pre(root);
        return tree;
    }
    void pre(TreeNode* root) {
        if (root != NULL) {
            tree.push_back(root->val);
            if (root->left != NULL) pre(root->left);
            if (root->right != NULL) pre(root->right);
        }
    }
private:
    vector<int> tree;
};


class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> order;
        vector<int> ans;
        TreeNode* temp;
        if (root != NULL) order.push(root);
        while (!order.empty()) {
            temp = order.top();
            ans.push_back(temp->val);
            order.pop();
            if (temp->right != NULL)
            order.push(temp->right);
            if (temp->left != NULL)
            order.push(temp->left);
        }
        return ans;
    }
};
