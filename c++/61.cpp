/** First time. 4/14/2015
 * 
 * Note the case where k is greater than the length of the list.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) {
            return NULL;
        }
        if (k == 0) {
            return head;
        }
        
        ListNode *start = new ListNode (0);
        start->next = head;
        ListNode *node1 = start;
        ListNode *node2 = start;
        int length = 0;
        
        while (node1->next) {
            node1 = node1->next;
            ++length;
        }
        
        int r = k % length;
        int i = 0;
        while (i < r) {
            node2 = node2->next;
            ++i;
        }
        node1 = start;
        while (node2->next) {
            node1 = node1->next;
            node2 = node2->next;
        }
        
        node2->next = head;
        head = node1->next;
        node1->next = NULL;
        return head;
    }
};