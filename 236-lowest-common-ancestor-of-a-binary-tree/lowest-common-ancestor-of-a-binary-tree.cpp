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

        if(root->val == p->val) return p;
        if(root->val == q->val) return q;

        TreeNode* leftSide = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightSide = lowestCommonAncestor(root->right,p,q);

        if(!leftSide && !rightSide) return NULL;
        else if(leftSide && !rightSide) return leftSide;
        else if(!leftSide && rightSide) return rightSide;
        else return root;

    }
};