/** First time. 4/22/2015
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev = NULL;
        ListNode *node = head;
        while (node) {
            if (node->val == val) {
                if (node == head) {
                    head = node->next;
                }
                else {
                    prev->next = node->next;
                }
            }
            else {
                prev = node;
            }
            node = node->next;
        }
        return head;
    }
};