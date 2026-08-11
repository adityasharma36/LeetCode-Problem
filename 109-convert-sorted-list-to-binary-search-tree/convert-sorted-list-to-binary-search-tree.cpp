
class Solution {
public:
    int getLenght(ListNode*&head){
        ListNode* temp = head;
        int cnt =0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    TreeNode* solve(ListNode* &head,int n){
        if(head == NULL || n<=0) return NULL;
        TreeNode* leftTree = solve(head,n/2);
        TreeNode* root = new TreeNode(head->val);
        root->left = leftTree;
        head = head->next;
        TreeNode* rightTree = solve(head,n-n/2-1);
        root->right = rightTree;

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n = getLenght(head);
        TreeNode* root = solve(head,n);
        return root;

    }
};