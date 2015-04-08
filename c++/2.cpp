/** 
 * First time. 4/7/2015
 * Linked list manipulation
 */

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        int carry = 0;
        ListNode *node = NULL;
        ListNode *prev = NULL;
        ListNode *head = NULL;
        bool isHead = true;
        while (l1 && l2) {
            node = new ListNode ((l1->val + l2->val + carry)%10);
            carry = (l1->val + l2->val + carry) / 10;
            if (isHead) {
                head = node;
                prev = head;
                isHead = false;
            }
            else {
                prev->next = node;
                prev = node;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            node = new ListNode ((l1->val + carry)%10);
            carry = (l1->val + carry) / 10;
            prev->next = node;
            prev = node;
            l1 = l1->next;
        }
        while (l2) {
            node = new ListNode ((l2->val + carry)%10);
            carry = (l2->val + carry) / 10;
            prev->next = node;
            prev = node;
            l2 = l2->next;
        }
        if (carry) {
            node = new ListNode (carry);
            prev->next = node;
        }
        return head;
    }
};