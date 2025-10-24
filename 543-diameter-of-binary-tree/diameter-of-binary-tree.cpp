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
    int getHeight(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int leftNode = getHeight(root->left);
        int rightNode = getHeight(root->right);
        return max(leftNode,rightNode) +1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root== nullptr){
            return 0;
        }

        int leftHe = diameterOfBinaryTree(root->left);
        int rightHe = diameterOfBinaryTree(root->right);
        int heig = getHeight(root->left) + getHeight(root->right);

        int maxLen = max(heig,max(leftHe,rightHe));
        return maxLen;
    }
};