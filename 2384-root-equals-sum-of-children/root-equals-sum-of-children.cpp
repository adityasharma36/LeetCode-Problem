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

   
    bool checkTree(TreeNode* root) {
     
     int bothSum = root->left->val + root->right->val;
     bool center = (bothSum== root->val) ? true: false;

     int leftSide = root->val + root->right->val;

     bool lef = (leftSide == root->left->val) ? true: false;
    
    int rightSide = root->val + root->left->val;
     bool righ = (rightSide == root->right->val) ? true : false;

     return (center || lef || righ);
    }
};