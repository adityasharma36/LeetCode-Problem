class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* rightRotate(ListNode* head, int k){

        if(!head || !head->next || k==0) return head;

        int total = 0;
        ListNode* temp = head;
        while(temp){
            total++;
            temp = temp->next;
        }

        int nRotation = k % total;
        if(nRotation == 0) return head;

        // Step 1: reverse full list
        head = reverse(head);

        // Step 2: move to nRotation-th node
        temp = head;
        for(int i = 1; i < nRotation; i++){
            temp = temp->next;
        }

        // Step 3: split
        ListNode* second = temp->next;
        temp->next = NULL;

        // Step 4: reverse both parts (IMPORTANT FIX)
        ListNode* first = reverse(head);
        second = reverse(second);

        // Step 5: join
        temp = first;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = second;

        return first; // FIXED
    }

    ListNode* rotateRight(ListNode* head, int k) {
        return rightRotate(head, k);
    }
};