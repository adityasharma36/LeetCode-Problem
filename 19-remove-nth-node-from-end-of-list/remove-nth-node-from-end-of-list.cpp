class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;

        int cnt = 0;
        ListNode* temp = head;

        // count length
        while (temp) {
            cnt++;
            temp = temp->next;
        }

        // if head needs to be removed
        if (n == cnt) {
            return head->next;
        }

        temp = head;
        int steps = cnt - n;

        // move to node just before target
        while (steps > 1) {
            temp = temp->next;
            steps--;
        }

        ListNode* curr = temp->next;
        temp->next = curr->next;
        curr->next = NULL;

        return head;
    }
};
