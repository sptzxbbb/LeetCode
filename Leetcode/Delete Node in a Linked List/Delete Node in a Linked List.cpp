/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        while (1) {
            node->val = node->next->val;
            if (node->next && NULL == node->next->next) {
                delete node->next;
                node->next = NULL;
                break;
            }
            node = node->next;
        }
        return;
    }
};

