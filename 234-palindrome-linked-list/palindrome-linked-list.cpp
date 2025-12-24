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
    void reverseLL(ListNode*& prev,ListNode*& curr){
        if(!curr) return;

        ListNode* ele = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ele;
        reverseLL(prev,curr);
    }
    bool palindromeCheck(ListNode* head){
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = slow->next;

        reverseLL(prev,curr);


        ListNode* temp = head;

        while(prev && temp){
            if(prev->val != temp->val) return false;

            prev = prev->next;
            temp= temp->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        return palindromeCheck(head);
    }
};