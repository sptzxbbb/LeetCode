#include <iostream>
#include <vector>


using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Solution1 {
// public:
//     bool isValidBST(TreeNode* root) {
//         valid(root, LONG_MIN, LONG_MAX);
//     }
//     bool valid(TreeNode* node, long MIN, long MAX) {
//         if (node == NULL) {
//             return true;
//         }
//         if (node->val > MIN &&
//             node->val < MAX &&
//             valid(node->left, MIN, node->val) &&
//             valid(node->right, node->val, MAX)) {
//             return true;
//         } else {
//             return false;
//         }
//     }
// };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(v, root);
        for (int i = 0; i < (int)v.size() - 1; i++) {
            if (v[i] >= v[i + 1]) {
                return false;
            }
        }
        return true;
    }

    void inorder(vector<int>& v, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorder(v, root->left);
        v.push_back(root->val);
        inorder(v, root->right);
        return;
    }
};

int main(int argc, char *argv[])
{
    TreeNode* root = NULL;
    Solution k;
    k.isValidBST(root);
    return 0;
}
