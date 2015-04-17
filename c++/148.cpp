/** First time. 4/16/2015
 * 
 * Bottom-up merge sort
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
    ListNode *sortList(ListNode *head) {
        int len = 0;
        ListNode *node = head;
        while (node) {
            ++len;
            node = node->next;
        }
		
        ListNode *start = new ListNode (0);
		start->next = head;
		ListNode *node1 = start;
		ListNode *node2 = start;
        for (int width = 1; width < len; width <<= 1) {
			node1 = start;
			node2 = start;
            for (int i = 0; i < len; i += 2*width) {
				int j = 0;
				while (j < min(width, len-i)) {
					node2 = node2->next;
					++j;
				}
				int len1 = min(width, len-i);
                merge(start, head, node1, len1, node2, min(width, len-i-len1));
				node1 = node2;
            }
        }
        return head;
    }
    
    void merge(ListNode *start, ListNode *&head, ListNode*& node1, int len1, ListNode*& node2, int len2) {
        int i = 0;
        int j = 0;
        while (i < len1 && j < len2) {
            if (node1->next->val <= node2->next->val) {
                node1 = node1->next;
                ++i;
            }
            else {
                ListNode *temp = node2->next->next;
                node2->next->next = node1->next;
                node1->next = node2->next;
                node2->next = temp;
				if (node1 == start) {
					head = start->next;
				}
				node1 = node1->next;
                ++j;
            }
        }
		while (j < len2) {
			node2 = node2->next;
			++j;
		}
    }
};