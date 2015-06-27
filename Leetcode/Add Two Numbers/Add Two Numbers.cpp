#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> digit1, digit2;
        ListNode *p1 = l1, *p2 = l2;
        while (p1 != NULL) {
            digit1.push_back(p1->val);
            p1 = p1->next;
        }
        while (p2 != NULL) {
            digit2.push_back(p2->val);
            p2 = p2->next;
        }


        int size = min(digit1.size(), digit2.size());
        // Addition
        for (int i = 0; i < size; i++) {
            if (digit1.size() >= digit2.size()) {
                digit1[i] += digit2[i];
            } else {
                digit2[i] += digit1[i];
            }
        }
        vector<int> ans;
        if (digit1.size() >= digit2.size()) {
            ans = digit1;
        } else {
            ans = digit2;
        }
        int carry = 0;
        // Deal with Carry
        size = ans.size();
        for (int i = 0; i < size; i++) {
            ans[i] += carry;
            carry = ans[i] / 10;
            ans[i] %= 10;
        }
        if (carry) {
            ans.push_back(1);
        }
        size = ans.size();
        ListNode *head, *last, *temp;
        for (int i = 0; i < size; i++) {
            if (0 == i) {
                head = new ListNode(ans[i]);
                last = head;
            } else {
                temp = new ListNode(ans[i]);
                last->next = temp;
                last = temp;
            }
        }
        return head;
    }
};

int main(int argc, char *argv[]) {
    ListNode a1(0), b1(7), b2(3);
    b1.next = &b2;
    Solution k;
    k.addTwoNumbers(&a1, &b1);
    return 0;
}
