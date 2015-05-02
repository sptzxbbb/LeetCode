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
    ListNode* removeElements(ListNode* head, int val) {
	// empty list
	if (NULL == head) {
	    return head;
	}
	// dummy node
	ListNode* phead = new ListNode(1);
	phead->next = head;
	ListNode *pre = phead, *pt = head, *temp;
	// at least one node
	while (pt != NULL) {
	    if (pt->val == val) {
		temp = pt;
		pre->next = pt->next;
		pt = pt->next;
		delete temp;
	    } else {
		pre = pre->next;
		pt = pt->next;
	    }
	}
	pt = phead->next;
	delete phead;
	return pt;
    }
};
