#include <iostream>
#include <stack>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome1(ListNode* head) {
        ListNode* p = head;
        stack<int> s;
        while (p != NULL) {
            s.push(p->val);
            p = p->next;
        }
        p = head;
        while (p != NULL) {
            if (p->val != s.top()) {
                return false;
            } else {
                p = p->next;
                s.pop();
            }
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        int count = 0;
        ListNode *p = head;
        if (NULL == p || NULL == p->next) {
            return true;
        }
        while (p != NULL) {
            ++count;
            p = p->next;
        }
        int half = count / 2 - 1;
        p = head;
        while (half != 0) {
            p = p->next;
            --half;
        }
        // get the starting node of the second half
        ListNode * second_half;
        if (0 == count % 2) {
            second_half = p->next;
        } else {
            second_half = p->next->next;
        }
        // reverse the second half of the list
        ListNode *pre = NULL, *cur = second_half, *temp = cur->next;
        while (cur != NULL) {
            cur->next = pre;
            pre = cur;
            cur = temp;
            if (cur != NULL) temp = cur->next;
        }
        second_half = pre;
        // compare the first half and the reverse of the second half
        ListNode* first_half = head;
        while (second_half != NULL) {
            if (first_half->val != second_half->val) {
                return false;
            }
            first_half = first_half->next;
            second_half = second_half->next;
        }
        return true;
    }
};

int main() {
    ListNode a(1), b(2), c(2), d(1);
    a.next = &b;
//    b.next = &c;
//    c.next = &d;
    
    Solution k;
    cout << k.isPalindrome(&a) << endl;
}