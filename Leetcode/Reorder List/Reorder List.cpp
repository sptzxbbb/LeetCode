#include <iostream>
#include <vector>
using namespace std;

// * Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* p = head, *middle = head;
        int move = 0;
        if (NULL == head || NULL == head->next || NULL == head->next->next) {
            return;
        }
        while (p != NULL) {
            ++move;
            if (0 == move % 2) {
                middle = middle->next;
            }
            p = p->next;
        }
        ListNode* second;

        second = middle->next;
        middle->next = NULL;

        vector<ListNode*> second_half;
        while (second != NULL) {
            second_half.push_back(second);
            second = second->next;
        }
        int size = second_half.size();
        p = head;
        for (int i = size - 1; i >= 0; --i) {
            second_half[i]->next = p->next;
            p->next = second_half[i];
            p = p->next->next;
        }
    }
};

int main(int argc, char *argv[]) {
    ListNode a(1), b(2), c(3), d(4);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    Solution k;
    k.reorderList(&a);
    return 0;
}
