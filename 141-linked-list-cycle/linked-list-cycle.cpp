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
    bool isCycle(ListNode*head){
        unordered_map<ListNode*,bool> um;

        while(head!= NULL){
            if(um[head]== true){
                return true;
            }else{
                um[head] = true;

                head = head->next;
            }
        }
        return false;
    }
    bool optimiseCode(ListNode* head){
        ListNode* fast  = head;
        ListNode* slow = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast!= NULL){
                fast = fast->next;
                slow = slow->next;
                if(fast == slow){
                    return true;
                }
            }
        }
        return false;
    }
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        // return isCycle(temp);
        return optimiseCode(temp);
    }
};