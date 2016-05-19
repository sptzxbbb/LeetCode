#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

void preorderTraversal(TreeNode* root) {
    stack<TreeNode*> order;
    TreeNode* temp;
    if (root != NULL) order.push(root);
    while (!order.empty()) {
        temp = order.top();
        cout << temp->val << ' ';
        order.pop();
        if (temp->right != NULL)
        order.push(temp->right);
        if (temp->left != NULL)
        order.push(temp->left);
    }
}

void inorderTraversal(TreeNode* root) {
    stack<TreeNode*> order;
    TreeNode* p = root;
    while (p != NULL || !order.empty()) {
        if (p != NULL) {
            order.push(p);
            p = p->left;
        } else {
            p = order.top();
            order.pop();
            cout << p->val << ' ';
            p = p->right;
        }
    }
}


void postorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    stack<int> s2;
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


int main(){
    TreeNode tree[7];
    for (int i = 0; i < 7; i++) {
        tree[i].val = i + 1;
    }
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];

    tree[1].left = &tree[3];
    tree[1].right = &tree[4];

    tree[2].left = &tree[5];
    tree[2].right = &tree[6];

    for (int i = 3; i < 7; i++) {
        tree[i].left = NULL;
        tree[i].right = NULL;
    }

    preorderTraversal(tree);
    cout << endl;
    inorderTraversal(tree);
    cout << endl;
    postorderTraversal(tree);
    cout << endl;
}

