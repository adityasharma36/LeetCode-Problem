class Solution {
public:

    // Reverse linked list
    ListNode* reverseEvenLL(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    ListNode* listOddEven(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        // Step 1: separate odd and even
        while(even && even->next){
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

    
       

        // Step 3: attach
        odd->next = evenHead;

        return head;
    }

    ListNode* oddEvenList(ListNode* head) {
        return listOddEven(head);
    }
};