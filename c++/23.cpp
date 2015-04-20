/** First time. 4/19/2015
 * 
 * Divide and conquer. Leverage "merge 2 sorted lists".
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        for (int step = 1; step < lists.size(); step <<= 1) {
            for (int i = 0; i < lists.size(); i += 2*step) {
                if (i + step < lists.size()) {
                    lists[i] = mergeLists(lists[i], lists[i + step]);
                }
            }
        }
        return lists[0];
    }
    
    ListNode *mergeLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        if (list1->val < list2->val) {
            list1->next = mergeLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeLists(list1, list2->next);
            return list2;
        }
    }
};