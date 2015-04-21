/** First time. 4/20/2015
 * 
 * 1. Find the middle point.
 * 2. Reverse the second half
 * 3. Merge the first half and the second half.
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
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return;
        }
        
        // Find middle point
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = NULL;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        }
        prev->next = NULL;
        
        // Reverse the second half
        ListNode *l2 = NULL;
        reverseList(slow, l2)->next = NULL;
        
        // Merge the two halves
        ListNode *l1 = head;
        while (l1 && l2) {
            ListNode *temp1 = l1->next;
            ListNode *temp2 = l2->next;
            l1->next = l2;
            if (temp1) {
                l2->next = temp1;
            }
            l1 = temp1;
            l2 = temp2;
        }
        
        return;
    }
    
    ListNode *reverseList(ListNode *node, ListNode*& head) {
        if (node->next == NULL) {
            head = node;
            return node;
        }
        reverseList(node->next, head)->next = node;
        return node;
    }
};