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
    ListNode* sortLinkedList(ListNode* head){
        vector<int> ans;
        ListNode* temp = head;
        while(temp != NULL){
            int val =temp->val;
            ans.push_back(val);
            temp = temp->next;
        }
        sort(ans.begin(),ans.end());
        temp = head;
        int index = 0;
        while(temp != NULL && index<ans.size()){
           temp->val = ans[index];
           index++;
            temp = temp->next;
        }
        return head;
    }
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
     return sortLinkedList(temp);
    }
};