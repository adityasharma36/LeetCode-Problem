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
    ListNode* isCycle(ListNode* temp){
        unordered_map<ListNode*,bool> um;

        while(temp!= NULL){
            ListNode* newTemp = temp;

           if(um[newTemp]==true){
            return newTemp;
           }
           um[newTemp]= true;
           temp = temp->next;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        return isCycle(head);
    }
};