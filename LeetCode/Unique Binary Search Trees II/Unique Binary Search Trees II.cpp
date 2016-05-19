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
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }

    vector<TreeNode*> generate(int left, int right) {
        vector<TreeNode*> ans;
        if (left > right) {
            ans.push_back(NULL);
            return ans;
        }
        for (int i = left; i <= right; i++) {
            vector<TreeNode*> leftTree = generate(left, i - 1);
            vector<TreeNode*> rightTree = generate(i + 1, right);
            for (int j = 0; j < leftTree.size(); j++) {
                for (int k = 0; k < rightTree.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree[j];
                    root->right = rightTree[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};