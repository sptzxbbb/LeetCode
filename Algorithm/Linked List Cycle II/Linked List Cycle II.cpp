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
    ListNode *detectCycle(ListNode *head) {
        ListNode *pslow = head, *pfast = head;
        do {
            if (NULL == pfast) {
                return NULL;
            }
            pfast = pfast->next;
            if (NULL == pfast) {
                return NULL;
            }
            pfast = pfast->next;

            pslow = pslow->next;
        } while (pslow != pfast);
        pfast = head;
        while (pfast != pslow) {
            pfast = pfast->next;
            pslow = pslow->next;
        }
        return pslow;
    }
};