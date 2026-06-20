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
    void pathSum(TreeNode* root,int targetSum,int sum ,vector<vector<int>>& path,vector<int>&temp){
        if(!root) return;

        sum+=root->val;
        temp.push_back(root->val);

        if(!root->left && !root->right && targetSum == sum){
            path.push_back(temp);
        }
        pathSum(root->left,targetSum,sum,path,temp);
        pathSum(root->right,targetSum,sum,path,temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>path;
        vector<int>temp;
        pathSum(root,targetSum,0,path,temp);
        return path;
    }
};