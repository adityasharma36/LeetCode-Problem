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
    vector<TreeNode*>solveByRec(int start,int end){
        if(start>end) return {nullptr};
        if(start==end) return { new TreeNode(start)};
        vector<TreeNode*>ans;
        for(int i = start;i<=end ;i++){
            auto leftSide = solveByRec(start,i-1);
            auto rightSide = solveByRec(i+1,end);
            for(int j = 0;j<leftSide.size();j++){
                for(int k = 0;k<rightSide.size();k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftSide[j];
                    root->right = rightSide[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        
        vector<TreeNode*> ans = solveByRec(1,n);
        return ans;
    }
};