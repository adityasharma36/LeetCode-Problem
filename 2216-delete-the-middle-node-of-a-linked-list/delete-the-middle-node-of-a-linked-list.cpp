class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // edge case: only one node
        if(head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // delete middle node
        prev->next = slow->next;

        return head;
    }
};