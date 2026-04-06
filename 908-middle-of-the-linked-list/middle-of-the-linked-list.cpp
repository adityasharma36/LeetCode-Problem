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
    ListNode* nodeMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
            if(fast->next){
                fast = fast->next;
            }
        }
        return slow;
    }
    ListNode* middleNode(ListNode* head) {
        return nodeMiddle(head);
    }
};