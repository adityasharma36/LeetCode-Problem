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
    void reverseGroup(queue<int>&qt,int k,int n){
        
        if(n>=k){
            stack<int>st;

            for(int i = 0;i<k;i++){
                int ele = qt.front();
                qt.pop();
                st.push(ele);
            }

            for(int i = 0;i<k;i++){
                int ele = st.top();
                st.pop();
                qt.push(ele);
            }
            reverseGroup(qt,k,n-k);
        }
        else{
            for(int i = 0;i<n;i++){
                int ele = qt.front();
                qt.pop();
                qt.push(ele);
            }
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;
        queue<int>qt;
        int n = 0;
        ListNode* temp = head;
        while(temp){
            qt.push(temp->val);
            n++;
            temp= temp->next;
        }
        if(n<k) return head;
        reverseGroup(qt,k,n);
        temp = head;
        while(temp && !qt.empty()){
           
            temp->val = qt.front();
            qt.pop();
            temp = temp->next;
        }
        return head;
    }
};