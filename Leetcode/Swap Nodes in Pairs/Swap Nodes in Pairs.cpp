

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // The list is consist of one node
        if (NULL == head || NULL == head->next) {
            return head;
        }
        // The list is consist of at least two nodes
        ListNode *pre, *cur, *temp = new ListNode(1), *last = temp;
        pre = head;
        cur = head->next;
        head = cur;
        while (1) {
            pre->next = cur->next;
            cur->next = pre;
            last->next = cur;
            last = pre;

            pre = pre->next;
            // no more node to swap
            if (NULL == pre) {
                break;
            }
            cur = pre;
            // only one more node left
            cur = cur->next;
            if (NULL == cur) {
                break;
            }
        }
        delete temp;
        return head;
    }
};

















