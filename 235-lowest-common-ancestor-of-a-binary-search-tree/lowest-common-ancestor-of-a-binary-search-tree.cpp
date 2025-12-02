/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;

        if(root->val < p->val && root->val < q->val){
            TreeNode * rightSide = lowestCommonAncestor(root->right , p, q);
            if(rightSide != NULL) return rightSide;
        }

        if(root-> val  > p->val && root-> val > q->val){
            TreeNode* leftSide = lowestCommonAncestor(root->left,p,q);
            if(leftSide != NULL) return leftSide;
        }
        return root;
    }
};