/** First time. 5/3/2015
 * 
 * Linked list
 */

class MinStack {
public:
    struct ListNode {
        int val;
        int minVal;
        ListNode *next;
        ListNode(int x, int y) : val(x), minVal(y), next(NULL) {}
    };
    
    ListNode *head = NULL;
    
    void push(int x) {
        int y;
        if (head) {
            y = (x < head->minVal) ? x : head->minVal;
        }
        else {
            y = x;
        }
        ListNode *temp = new ListNode(x, y);
        temp->next = head;
        head = temp;
    }

    void pop() {
        if (head) {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
    }

    int top() {
        return (head) ? head->val : -1;
    }

    int getMin() {
        return head->minVal;
    }
};