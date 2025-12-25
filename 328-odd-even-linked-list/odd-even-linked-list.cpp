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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* oddNode = head;
        ListNode* evenNode = head->next;
        ListNode* even = evenNode;

        while(evenNode && evenNode->next){

            oddNode->next = evenNode->next;
            oddNode = evenNode->next;

            evenNode->next = oddNode->next;
            evenNode = oddNode->next;
        }

    oddNode->next = even;
    return head;
       
    }
};