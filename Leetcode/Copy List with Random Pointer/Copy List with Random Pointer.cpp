/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (NULL == head) {
            return NULL;
        }
        // insert the copy nodes into the list
        RandomListNode *cur = head, *next;
        while (cur) {
            next = cur->next;
            RandomListNode *copy = new RandomListNode(cur->label);
            copy->next = next;
            cur->next = copy;
            cur = next;
        }
        // deal with random pointers
        cur = head;
        while (cur) {
            cur->next->random = (cur->random == NULL ? NULL : cur->random->next);
            cur = cur->next->next;
        }
        // decouple two lists
        cur = head;
        RandomListNode* head2 = head->next, *cur2 = head2;
        while (cur) {
            cur->next = cur->next->next;
            if (cur2->next) {
                cur2->next = cur2->next->next;
            }
            cur = cur->next;
            cur2 = cur2->next;
        }
        return head2;
    }
};