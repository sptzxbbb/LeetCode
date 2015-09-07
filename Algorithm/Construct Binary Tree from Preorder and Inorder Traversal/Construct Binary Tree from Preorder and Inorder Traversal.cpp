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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        return buildSubTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder, int s1, int e1, int s2, int e2) {
        if (s1 > e1 || s2 > e2) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[s1]);
        int rootIndex = -1;
        for (int i = s2; i <= e2; i++) {
            if (inorder[i] == root->val) {
                rootIndex = i;
                break;
            }
        }
        int leftTreeSize = rootIndex - s2;
        int rightTreeSize = e2 - rootIndex;
        root->left = buildSubTree(preorder, inorder, s1 + 1, s1 + leftTreeSize, s2, rootIndex - 1);
        root->right = buildSubTree(preorder, inorder, s1 + leftTreeSize + 1, e1, rootIndex + 1, e2);
        return root;
    }
};