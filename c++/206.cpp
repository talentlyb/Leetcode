/** First time. 5/4/2015
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        stack<ListNode*> st;
        while (head) {
            st.push(head);
            head = head->next;
        }
        head = st.top();
        st.pop();
        ListNode *prev = head;
        while (!st.empty()) {
            ListNode *temp = st.top();
            st.pop();
            prev->next = temp;
            prev = temp;
        }
        prev->next = NULL;
        return head;
    }
};