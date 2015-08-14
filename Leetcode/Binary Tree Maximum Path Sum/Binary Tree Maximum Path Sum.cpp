#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        visit(root, maxSum);
        return maxSum;
    }
    int visit(TreeNode* root, int& maxSum) {
        if (root == NULL) {
            return INT_MIN;
        }
        int leftSum = visit(root->left, maxSum);
        int rightSum = visit(root->right, maxSum);
        int path = root->val;
        if (leftSum > 0) {
            path += leftSum;
        }
        if (rightSum > 0) {
            path += rightSum;
        }
        maxSum = max(maxSum, path);
        int subpath = root->val;
        if (max(leftSum, rightSum) > 0) {
            subpath += max(leftSum, rightSum);
        }
        return subpath;
    }
};

int main(int argc, char *argv[])
{
    TreeNode a(2), b(-1);
    a.left = &b;
    Solution k;
    cout << k.maxPathSum(&a) << endl;
    
    return 0;
}
