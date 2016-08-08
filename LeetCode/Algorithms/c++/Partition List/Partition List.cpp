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
    ListNode* partition(ListNode* head, int x) {
        if (NULL == head) {
            return NULL;
        }
        ListNode* p = head;
        list<ListNode*> less, greater;
        while (p != NULL) {
            if (p->val < x) {
                less.push_back(p);
            } else {
                greater.push_back(p);
            }
            p = p->next;
        }
        while (greater.size()) {
            less.push_back(greater.front());
            greater.pop_front();
        }
        int size = less.size();
        ListNode* newHead = less.front();
        p = newHead;
        less.pop_front();
        while (less.size()) {
            p->next = less.front();
            p = p->next;
            less.pop_front();
        }
        p->next = NULL;
        return newHead;
    }
};