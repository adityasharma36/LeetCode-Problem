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
    // helper: reverse linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* addTwoNumb(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return NULL;
        if(l1!= NULL && l2 == NULL) return l1;
        if(l2 != NULL && l1 == NULL) return l2;

        ListNode* newNode = NULL;
        int carry = 0;

        while(l1!= NULL && l2 != NULL){
            int numb1 = l1->val;
            int numb2 = l2->val;
            int sum = numb1 + numb2 + carry;   // ✅ added carry here
            carry = sum / 10;
            int digit = sum % 10;

            ListNode* temp = new ListNode(digit);
            temp->next = newNode;
            newNode= temp;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL){
            int numb1 = l1->val;
            int sum = carry + numb1;
            carry = sum/10;
            int digit = sum%10;
            ListNode* temp = new ListNode(digit);
            temp->next = newNode;
            newNode= temp;
            l1 = l1->next;
        }

        while(l2 != NULL){
            int numb1 = l2->val;
            int sum = carry + numb1;
            carry = sum/10;
            int digit = sum%10;
            ListNode* temp = new ListNode(digit);
            temp->next = newNode;
            newNode= temp;
            l2 = l2->next;
        }

        if(carry > 0){   // ✅ handle leftover carry
            ListNode* temp = new ListNode(carry);
            temp->next = newNode;
            newNode = temp;
        }

        return reverseList(newNode);   // ✅ use reverseList instead of STL reverse
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumb(l1,l2);
    }
};
