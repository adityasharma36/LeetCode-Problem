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
    int solve(TreeNode* root){
        if(!root) return 0;
        int left = solve(root->left);
        int right = solve(root->right);

        int maxLen = max(left,right);

        return maxLen+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int leftSide = solve(root->left);
        int rightSide = solve(root->right);
        
        bool ans = abs(leftSide-rightSide)<=1;

        if(!ans) return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if(left && right) return true;
        return false;
    }
};