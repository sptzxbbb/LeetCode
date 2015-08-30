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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string s = "";
        next(res, s, root);
        return res;
    }
    void next(vector<string>& res, string path, TreeNode* cur) {
        if (cur == NULL) {
            return;
        }
        char temp[20];
        sprintf(temp, "%d", cur->val);
        string newPath = path + temp;
        if (!cur->left && !cur->right) {
            res.push_back(newPath);
            return;
        }
        newPath += "->";
        next(res, newPath, cur->left);
        next(res, newPath, cur->right);
        return;
    }
};