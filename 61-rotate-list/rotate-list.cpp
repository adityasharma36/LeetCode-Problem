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
    // helper to reverse part of array
    void swapArray(vector<int>& ans,int start ,int end){
        while(start <= end){
            swap(ans[start], ans[end]);
            start++;
            end--;
        }
    }

    ListNode* rotateNode(ListNode* head,int k){
        if(head == NULL || head->next == NULL || k == 0) return head;

        // copy linked list values into vector
        vector<int> ans;
        ListNode* temp = head;
        while(temp != NULL){
            ans.push_back(temp->val);
            temp = temp->next;
        }

        int n = ans.size();

        k = k % n;   

        if(k == 0) return head; // no rotation needed

        // Reverse method for right rotation
        swapArray(ans, 0, n-1);
        swapArray(ans, 0, k-1);
        swapArray(ans, k, n-1);

        // put back value into linked list

        temp = head;
        int index = 0;
        while(temp != NULL && index < n){
            temp->val = ans[index];
            index++;
            temp = temp->next;
        }

        return head;   //  return head
    }

    ListNode* rotateRight(ListNode* head, int k) {
        return rotateNode(head,k);
    }
};
