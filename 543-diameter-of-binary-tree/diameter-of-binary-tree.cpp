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
    int D = 0;
    int solve(TreeNode * root){
        if(!root) return 0;

        int left = solve(root->left);
        int right = solve(root->right);
        int currHe = left+ right;
        D = max(currHe,D);
        return max(left,right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        // int combineBoth = solve(root->left) + solve(root->right);

        // int left = diameterOfBinaryTree(root->left);
        // int right = diameterOfBinaryTree(root->right);

        // return max({left,right,combineBoth});
        solve(root);
        return D;
    }
};