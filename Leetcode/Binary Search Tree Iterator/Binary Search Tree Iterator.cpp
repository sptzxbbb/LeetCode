/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.size();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *p = s.top();
        s.pop();
        int ans = p->val;
        if (p->right != NULL) {
            p = p->right;
            while (p) {
                s.push(p);
                p = p->left;
            }
        }
        return ans;
    }

private:
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */