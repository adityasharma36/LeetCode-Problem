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
    void reverseNode(ListNode*&curr,ListNode*& next){
        if(curr== NULL) return;
        ListNode* temp = curr->next;
        curr->next = next;
        next = curr;
        curr= temp;
        reverseNode(curr,next);
    }
    bool constSpace(ListNode* head){
        bool answer = true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * prev = NULL;
        ListNode* curr = slow->next;
        reverseNode(curr,prev);

        ListNode * newList = prev;
        ListNode* newNode  = head;

        while(newList!= NULL){
            if(newList->val != newNode->val){
                answer = false;
                break;
            }

            newList= newList->next;
            newNode = newNode->next;
        }
        return answer;
    }
    bool isPalindrome(ListNode* head) {
        // return withArrayMethod(head);
        ListNode* temp = head;
        return constSpace(temp);
    }
};