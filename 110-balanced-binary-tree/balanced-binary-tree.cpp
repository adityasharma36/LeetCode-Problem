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
    int maxHeight(TreeNode* root){
        if(!root) return 0;

        int leftNode = maxHeight(root->left);
        int rightNode = maxHeight(root->right);
        int maxNode = max(leftNode,rightNode)+1;
        return maxNode;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int lfh = maxHeight(root->left);
        int rgh = maxHeight(root->right);

        int  diff = abs(lfh-rgh);

        bool isTree = (diff<=1);

        bool leftSide = isBalanced(root->left);
        bool rightSide = isBalanced(root->right);

        if(isTree && leftSide &&rightSide) return true;

        return false;
    }
};