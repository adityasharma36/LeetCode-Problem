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
    int total = 0;
    void includeNotIncludeMethod(TreeNode* root,long long targetSum){
       
       if(!root) return;
        if(root->val == targetSum){
            total++;
        }
        long long sum = targetSum - root->val;

        includeNotIncludeMethod(root->left , sum);

        includeNotIncludeMethod(root->right,sum);

        
    }
    int pathSum(TreeNode* root, int targetSum) {

        if(!root) return 0;
        includeNotIncludeMethod(root,targetSum);

        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return total;
    }
};