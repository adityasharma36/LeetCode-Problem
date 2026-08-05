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
    void puttingVal(TreeNode* root , vector<int>& ans){
        if(!root) return;

        puttingVal(root->left,ans);
        ans.push_back(root->val);
        puttingVal(root->right,ans);
    }
    int cnt = 0;
    int ans = -1;
    void secondMethod(TreeNode* root,int k){
        if(!root) return ;
        secondMethod(root->left,k);
        cnt++;
        if(cnt == k) {
            ans = root->val;
            return;
        };
       secondMethod(root->right,k);

        
    }
    int kthSmallest(TreeNode* root, int k) {
        // vector<int> ans;
        // puttingVal(root,ans);

        // return ans[k-1];
      secondMethod(root,k); 
      return ans;

    }
};