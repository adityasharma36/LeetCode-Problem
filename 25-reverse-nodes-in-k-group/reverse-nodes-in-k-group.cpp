/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int linkedList(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp!= NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode* reverseLinkedList(ListNode* head, int k){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(k-- && curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseGroup(ListNode* head, int k, int len){
        if(len < k) return head; 

        
        ListNode* curr = head;
        int count = 0;

        while(count < k && curr != NULL){
            curr = curr->next;
            count++;
        }

        ListNode* newHead = reverseLinkedList(head, k);

        head->next = reverseGroup(curr, k, len - k);

        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int llSize = linkedList(head);
        return reverseGroup(head, k, llSize);
    }
};
