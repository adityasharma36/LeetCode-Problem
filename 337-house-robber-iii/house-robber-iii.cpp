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
    int solveByRec(TreeNode* root){
        if(!root) return 0;

        int incl= 0;
        int excl = 0;
        incl+=root->val;
        if(root->left){
            incl +=solveByRec(root->left->left)+solveByRec(root->left->right);
        }
        if(root->right){
            incl += solveByRec(root->right->right)+solveByRec(root->right->left);
        }
        excl = solveByRec(root->left) + solveByRec(root->right);
        return max(incl,excl);
    }
    int solveByMemo(TreeNode* root,unordered_map<TreeNode*,int>&dp){
        if(!root) return 0;
        if(dp.find(root) != dp.end()) return dp[root];
        int incl = 0;
        int excl = 0;
        incl+= root->val;
        if(root->left){
            incl+=solveByMemo(root->left->left,dp) + solveByMemo(root->left->right,dp);
        }
        if(root->right){
            incl+=solveByMemo(root->right->right,dp) + solveByMemo(root->right->left,dp);
        }
        excl = solveByMemo(root->left,dp) + solveByMemo(root->right,dp);
        dp[root]= max(incl,excl);
        return dp[root];
    }
    int rob(TreeNode* root) {
        // int ans = solveByRec(root);
        unordered_map<TreeNode* , int>um;
        int ans = solveByMemo(root,um);
        return ans;
    }
};