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
    int maxHeight(TreeNode* root){
        if(!root) return 0;

        int leftSide = maxHeight(root->left);
        int rightSide = maxHeight(root->right);
        int maxSide = max(leftSide,rightSide)+1;
        return maxSide;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;


        int leftSide = diameterOfBinaryTree(root->left);
        int rightSide = diameterOfBinaryTree(root->right);
        int hei = maxHeight(root->left) + maxHeight(root->right);
        

        int ans = max(hei, max(leftSide,rightSide));

        return ans;

    }
};