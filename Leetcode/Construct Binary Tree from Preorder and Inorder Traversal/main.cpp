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
        TreeNode *p;
        TreeNode *root;
        stack<TreeNode *> stn;
        int size = preorder.size();
        if (0 == size) {
            return NULL;
        }
        int i = 0, j = 0;
        root = new TreeNode(preorder[i]);
        ++i;
        stn.push(root);
        while (true) {
            if (inorder[j] == stn.top()->val) {
                p = stn.top();
                stn.pop();
                ++j;
                if (j == size) {
                    break;
                }
                if (stn.size() && inorder[j] == stn.top()->val) {
                    continue;
                }
                p->right = new TreeNode(preorder[i]);
                ++i;
                stn.push(p->right);
            } else {
                p = new TreeNode(preorder[i]);
                ++i;
                stn.top()->left = p;
                stn.push(p);
            }
        }
        return root;
    }
};