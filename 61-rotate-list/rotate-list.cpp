class Solution {
public:
    void reverseLL(ListNode* &head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;   // 🔥 IMPORTANT FIX
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find length
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }

        k = k % len;
        if (k == 0) return head;

        // Step 2: Reverse whole list
        reverseLL(head);

        // Step 3: Split after k nodes
        temp = head;
        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }

        ListNode* second = temp->next;
        temp->next = NULL;

        // Step 4: Reverse both parts
        reverseLL(head);
        reverseLL(second);

        // Step 5: Join lists
        temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = second;

        return head;
    }
};
