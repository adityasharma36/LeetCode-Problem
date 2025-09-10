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
    bool isPalindr(ListNode* head){
        if(head == NULL) return true;
        vector<int>ans;
        ListNode* temp = head;
        while(temp!= NULL){
            int value = temp->val;
            ans.push_back(value);
            temp = temp->next;
        }

        int end = ans.size()-1;
        int start = 0;
        while(start<=end){
            if(ans[start]!= ans[end]){
                return false;
            }
            end--;
            start++;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        return isPalindr(head);
    }
};