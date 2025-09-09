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
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        return isCycle(temp);
    }
};