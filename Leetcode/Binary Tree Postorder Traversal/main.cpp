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
    vector<int> postorderTraversal(TreeNode* root) {
        post(root);
        return tree;
    }
    void post(TreeNode* root) {
        if (root != NULL) {
            if (root->left != NULL) post(root->left);
            if (root->right != NULL) post(root->right);
            tree.push_back(root->val);
        }
    }
private:
    vector<int> tree;
};

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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        while (root != NULL || !s.empty()) {
            if (root != NULL) {
                ans.push_back(root->val);
                s.push(root);
                root = root->right;
            } else {
                root = s.top();
                s.pop();
                root = root->left;
            }
        }
        for (int i = 0; i < ans.size() / 2; i++) {
            swap(ans[i], ans[ans.size() - 1 - i]);
        }
        return ans;
    }
};


void postorderTraversal(TreeNode* root) {
    stack<TreeNode*> s, s2;
    while (root != NULL || !s.empty()) {
        if (root != NULL) {
            s2.push(root->val);
            s.push(root);
            root = root->right;
        } else {
            root = s.top();
            s.pop();
            root = root->left;
        }
    }
    while (!s2.empty()) {
        cout << s2.top() << ' ';
        s2.pop();
    }
}
