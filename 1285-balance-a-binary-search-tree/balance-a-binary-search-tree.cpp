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
    void traversalOrder(TreeNode* root , vector<int> & inorder){
        if(!root ) return;

        traversalOrder(root->left,inorder);
        inorder.push_back(root->val);
        traversalOrder(root->right,inorder);
    }
    TreeNode* buildBST( vector<int> &preorder,int start ,int end){
        if(start>end) return NULL;
        int mid = start + (end-start)/2;

        TreeNode * root = new TreeNode(preorder[mid]);

        root->left = buildBST(preorder,start,mid-1);
        root->right = buildBST(preorder,mid + 1, end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        traversalOrder(root,inorder);
        return buildBST(inorder, 0 , inorder.size()-1);
    }
};