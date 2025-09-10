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
    int getLen(ListNode* head){
        int count = 0;
        ListNode * temp = head;
        while(temp!= NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* removeNode(ListNode* head,int n){
        
        int len = getLen(head);
        int getEleIndex = len-n;
        if(n == len) {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
        }
        int count = 0;
        ListNode* temp = head;
        while(count<getEleIndex-1){
            count++;
            temp = temp->next;
        }
        ListNode* removeNode = temp->next;
        ListNode* nextNode = removeNode->next;
        temp->next = nextNode;
        removeNode->next = NULL;
        delete removeNode;

        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return removeNode(head,n);
    }
};