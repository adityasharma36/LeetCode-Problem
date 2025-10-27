/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool ans = true;
    void isSame(TreeNode* p ,TreeNode* q){
        // base case pata nahiii

        if(p == NULL && q== NULL){

            return;
        }

        if(p== NULL && q != NULL){
            ans = false;
            return;
        }

        if(p != NULL && q == NULL){
            ans = false;
            return;
        }

        if(p->val != q->val){
            ans = false;
            return;
        }


        // ek case me solve karoga or bakkii recursion handle karega
        isSame(p->left,q->left);
        isSame(p->right,q->right);


       
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
     isSame(p,q);
     return ans;
    }
};