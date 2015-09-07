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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int step = n - m;
        // no need to reverse any nodes
        if (0 == step) {
            return head;
        }

        ListNode* safeG = new ListNode(-1);
        safeG->next = head;
        head = safeG;
        ListNode* pre = head;
        while (m > 1) {
            pre = pre->next;
            --m;
        }
        ListNode* cur = pre->next, *post = cur->next, *temp;
        while (step > 0 && post != NULL) {
            temp = post->next;
            post->next = cur;
            cur = post;
            post = temp;
            --step;
        }
        temp = pre->next;
        pre->next  = cur;
        temp->next = post;
        head = head->next;
        delete safeG;
        return head;
    }
};