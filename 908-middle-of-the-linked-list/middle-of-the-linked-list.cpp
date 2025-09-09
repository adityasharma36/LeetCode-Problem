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
    ListNode* midNode(ListNode *& head){
        ListNode* toto = head;
        ListNode* rabbit = head;

        while(rabbit!= NULL){
            rabbit = rabbit->next;
            if(rabbit != NULL){
                rabbit = rabbit->next;
                toto = toto->next;
            }
            
        }
        return toto;
    }
    ListNode* middleNode(ListNode* head) {
        return midNode(head);
    }
};