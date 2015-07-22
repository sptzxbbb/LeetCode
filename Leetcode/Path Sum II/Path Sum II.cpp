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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<int> v;
        vector<vector<int> > ans;
        if (root) {
            dfs(ans, v, sum, root);
        }
        return ans;
    }
    void dfs(vector<vector<int> >& ans, vector<int>& v, int sum, TreeNode* root) {
        int newSum = sum - root->val;
        if (0 == newSum && !root->left && !root->right) {
            v.push_back(root->val);
            ans.push_back(v);
            v.pop_back();
            return;
        } else {
            v.push_back(root->val);
            if (root->left) {
                dfs(ans, v, newSum, root->left);
            }
            if (root->right) {
                dfs(ans, v, newSum, root->right);
            }
            v.pop_back();
            return;
        }
    }
};