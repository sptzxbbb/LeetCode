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
        ListNode *pslow = head, *pfast = head;
        do {
            if (NULL == pfast) {
                return false;
            }
            pfast = pfast->next;
            if (NULL == pfast) {
                return false;
            }
            pfast = pfast->next;

            pslow = pslow->next;
        } while (pslow != pfast);
        return true;
    }
};