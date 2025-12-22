/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* unorMapSol(ListNode* head){
        unordered_map<ListNode* , bool> um;

        ListNode* temp = head;

        while(temp){

            if(um[temp])return temp;

            um[temp]= true;
            temp = temp->next;
        }
        return NULL;
    }
    ListNode* optimiseSpace(ListNode* head){

        ListNode* rabi = head;
        ListNode* toto = head;

        while(rabi && rabi->next){
            toto = toto->next;
            rabi = rabi->next->next;

            if(toto == rabi){
                toto = head;

                while(toto != rabi){
                    toto = toto->next;
                    rabi = rabi->next;
                }
                return toto;
            }
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        
        // return unorMapSol(head);

        return optimiseSpace(head);
    }
};