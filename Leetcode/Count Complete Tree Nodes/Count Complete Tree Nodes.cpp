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
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int heightL = 0, heightR = 0;
        TreeNode *l = root, *r = root;
        while (l) {
            ++heightL;
            l = l->left;
        }
        while (r) {
            ++heightR;
            r = r->right;
        }
        if (heightL == heightR) {
            return pow(2, heightL) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        // calculate the depth of tree
        int depth = 0;
        TreeNode* node = root;
        while (node) {
            ++depth;
            node = node->left;
        }
        int left = 0, right = (1 << (depth - 1)) - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (getNode(root, mid, depth)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return (1 << (depth - 1)) + right;
    }

    bool getNode(TreeNode* root, int path, int depth) {
        for (int i = depth - 2; i >= 0; --i) {
            if (path & (1 << i)) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return root != NULL;
    }
};