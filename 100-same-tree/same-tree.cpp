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
    bool treeSame(TreeNode* p ,TreeNode*q){
            if(!p && !q) return true;
            if(p && !q) return false;
            if(!p && q) return false;
            if(p->val != q->val) return false;
            
            bool leftSide = treeSame(p->left,q->left);
            bool rightSide = treeSame(p->right,q->right);

            return (leftSide && rightSide);

    } 
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return treeSame(p,q);
    }
};