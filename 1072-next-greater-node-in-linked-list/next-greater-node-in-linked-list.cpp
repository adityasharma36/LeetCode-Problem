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
    // void nextLarge(vector<int>& temp , vector<int>& ans){
    //     stack<int>st;
    //     st.push(-1);
    //     int n = temp.size();
    //     for(int i = n-1;i>=0;i--){
    //         while(st.top() != -1 && temp[i]>=st.top()){
    //             st.pop();
    //         }
    //         st.top() == -1 ? ans.push_back(0) : ans.push_back(st.top());
    //         st.push(temp[i]);
    //     }
    //     reverse(ans.begin(),ans.end());
    // }
    // vector<int>nextLargerNode(ListNode* head){
    //     vector<int>temp;
    //     while(head){
    //         int val = head->val;
    //         temp.push_back(val);
    //         head = head->next;
    //     }
    //     vector<int>ans;
    //     nextLarge(temp,ans);

    //     return ans;
    // }
    ListNode* reverse(ListNode* head,ListNode* prev){
        if(!head) return prev;

        ListNode* tempHead = head->next;
        head->next = prev;
        return reverse(tempHead,head);
    }
    vector<int>littleOptimse(ListNode* head){

        vector<int>ans;
        stack<ListNode*> st;

        ListNode* prev=  reverse(head,nullptr);

        while(prev){
            while(!st.empty() && st.top()->val <= prev->val){

                st.pop();

            }
            st.empty() ? ans.push_back(0) : ans.push_back(st.top()->val);

            st.push(prev);
            prev = prev->next;
        }

        std::reverse(ans.begin(),ans.end());

        return ans;
        

    }
    vector<int> nextLargerNodes(ListNode* head) {
        // return nextLargerNode(head);
        return littleOptimse(head);
    }
};