/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
    void dfs(TreeNode* root, int sum) {
        if (!root) {
            return;
        } else {
            sum = sum * 10 + root->val;
            if (root->left) {
                dfs(root->left, sum);
            }
            if (root->right) {
                dfs(root->right, sum);
            }
            if (!root->left && !root->right) {
                ans += sum;
            }
            return;
        }
    }
private:
    int ans;
};

int main(int argc, char *argv[]) {
    TreeNode a(9);
    Solution k;
    k.sumNumbers(&a);
    return 0;
}
