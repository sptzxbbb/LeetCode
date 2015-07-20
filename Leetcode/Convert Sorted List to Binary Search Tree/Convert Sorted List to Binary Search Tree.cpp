/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<TreeNode*> node;
        while (head != NULL) {
            TreeNode* p = new TreeNode(head->val);
            node.push_back(p);
            head = head->next;
        }
        TreeNode* newHead = generate(node, 0, node.size() - 1);
        return newHead;
    }
    TreeNode* generate(vector<TreeNode*>& node, int start, int end) {
        if (start > end) {
            return NULL;
        } else if (start == end) {
            return node[start];
        } else {
            int mid = (start + end) / 2;
            node[mid]->left = generate(node, start, mid - 1);
            node[mid]->right = generate(node, mid + 1, end);
            return node[mid];
        }
    }
};