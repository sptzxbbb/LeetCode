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
    bool isSymmetric(TreeNode* root) {
        if (NULL == root) {
            return true;
        } else if (NULL == root->left && NULL == root->right) {
            return true;
        } else if (root->left != NULL && root->right != NULL) {
            left.push(root->left);
            right.push(root->right);
        } else {
            return false;
        }
        TreeNode *l_node, *r_node;
        while (!left.empty()) {
            l_node = left.top();
            r_node = right.top();
            left.pop();
            right.pop();
            if ((l_node->val != r_node->val) ||
                (l_node->left && !r_node->right) ||
                (l_node->right && !r_node->left) ||
                (!l_node->left && r_node->right) ||
                (!l_node->right && r_node->left)
                ) {
                return false;
            }
            if (l_node->left)
            left.push(l_node->left);
            if (l_node->right)
            left.push(l_node->right);
            if (r_node->right)
            right.push(r_node->right);
            if (r_node->left)
            right.push(r_node->left);
        }
        return true;
    }

private:
    stack<TreeNode*> left, right;
};