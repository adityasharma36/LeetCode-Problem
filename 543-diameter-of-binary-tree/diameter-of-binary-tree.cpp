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
    int heightOfBinaryTree(TreeNode* root){
        if(!root) return 0;

        int leftSide = heightOfBinaryTree(root->left);
        int rightSide = heightOfBinaryTree(root->right);

        return 1+ max(leftSide,rightSide);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;
        int leftSide = diameterOfBinaryTree(root->left);
        int rightSide = diameterOfBinaryTree(root->right);
        int bothSide = heightOfBinaryTree(root->left) + heightOfBinaryTree(root->right);


        return max({leftSide,rightSide,bothSide});
    }
};