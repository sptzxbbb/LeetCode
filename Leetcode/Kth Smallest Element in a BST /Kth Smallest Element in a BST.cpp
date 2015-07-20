#include <iostream>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int _k = k;
        inorder(root, _k, ans);
        return ans;
    }
    void inorder(TreeNode* root, int& k, int& ans) {
        if (NULL == root) {
            return;
        }
        if (root->left) {
            inorder(root->left, k, ans);
        }
        if (1 == k) {
            ans = root->val;
            --k;
            return;
        } else if (k <= 0) {
            return;
        }
        --k;
        if (root->right) {
            inorder(root->right, k, ans);
        }
        return;
    }
};

int main(int argc, char *argv[]) {
    TreeNode a(2), b(1);
    a.left = &b;
    Solution k;
    k.kthSmallest(&a, 1);
    return 0;
}
