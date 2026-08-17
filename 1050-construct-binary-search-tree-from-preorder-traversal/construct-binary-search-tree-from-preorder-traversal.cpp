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
    TreeNode* bst(vector<int>& preorder,int & pre_Index,int& min_bound, int& max_bound){
        if(pre_Index >= preorder.size()) return nullptr;
        
        TreeNode* root = nullptr;

        if(min_bound < preorder[pre_Index] && preorder[pre_Index]< max_bound){
           
            root = new TreeNode(preorder[pre_Index++]);
            root->left = bst(preorder, pre_Index,min_bound, root->val);
            root->right = bst(preorder,pre_Index,root->val,max_bound);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min_bound = INT_MIN;
        int max_bound = INT_MAX;
        int i  = 0;
        return bst(preorder,i,min_bound,max_bound);
    }
};