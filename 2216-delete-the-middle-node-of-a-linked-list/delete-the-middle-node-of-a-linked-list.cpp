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
    ListNode* deletMidNode(ListNode*head){
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* rabbit = head;
        ListNode* totorise = head;
        ListNode* prev = NULL;
        while(rabbit != NULL && rabbit->next != NULL){
            prev = totorise;
            totorise = totorise->next;
            rabbit = rabbit->next->next;
        }
        prev->next = totorise->next;

        totorise->next = NULL;

        delete totorise;

        return head;
    }
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp = head;
        return deletMidNode(temp);
    }
};