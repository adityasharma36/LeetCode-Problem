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
    int findIndex(vector<int>& inorder,int ele){

        int n = inorder.size();

        for(int i = 0;i<n;i++){

            if(inorder[i]==ele){

                return i;

            }
        }

        return -1;
    }
    TreeNode* constructTree(vector<int>& inorder,vector<int>& postorder,int stIn,int enIn,int &enPo,int n){

        if(stIn>enIn) return NULL;

        if(enPo<0) return NULL;

        int ele = postorder[enPo];

        enPo--;

        TreeNode * root = new TreeNode(ele);

        int findIn = findIndex(inorder,ele);

        root->right = constructTree(inorder,postorder,findIn+1,enIn,enPo,n);
        root->left = constructTree(inorder,postorder,stIn,findIn-1,enPo,n);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int stIn = 0;
        int n = inorder.size();
        int enIn = n-1;
        int enPo = n-1;
        TreeNode* root = constructTree(inorder,postorder,stIn,enIn,enPo,n);
        return root;
    }
};