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
    bool hasCycle(ListNode *head) {
        if (NULL == head || NULL == head->next) {
            return false;
        }
        ListNode *p1 = head, *p2 = head->next;
        while (1) {
            p1 = p1->next;
            p2 = p2->next;
            if (NULL == p2) {
                return false;
            }
            p2 = p2->next;
            if (NULL == p2) {
                return false;
            }
            if (p1 == p2) {
                return true;
            }
        }
    }
};