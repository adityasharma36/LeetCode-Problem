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
        if(!root) return 0;
        int leftSide = getHeight(root->left);
        int rightSide = getHeight(root->right);
        return 1 + max(leftSide,rightSide);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int leftSide = getHeight(root->left);
        int rightSide = getHeight(root->right);

        int diff = abs(leftSide-rightSide);

        bool ans = diff<=1 ? true: false;

        if(!ans) return false;

        bool leftBala = isBalanced(root->left);
        bool rightBala = isBalanced(root->right);

        return (leftBala && rightBala);
    }
};