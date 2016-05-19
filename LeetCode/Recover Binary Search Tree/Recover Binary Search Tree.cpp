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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> q;
        vector<int> val;
        InOrderTravel(root, q, val);
        sort(val.begin(), val.end());
        int size = q.size();
        for (int i = 0; i < size; i++) {
            q[i]->val = val[i];
        }
        return;
    }
    void InOrderTravel(TreeNode* root, vector<TreeNode*>& q, vector<int>& val) {
        if (NULL == root) {
            return;
        }
        InOrderTravel(root->left, q, val);
        q.push_back(root);
        val.push_back(root->val);
        InOrderTravel(root->right, q, val);
        return;
    }
};