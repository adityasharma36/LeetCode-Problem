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
    int depthMax(TreeNode* &root){
        if(!root) return 0;

        int leftNode = depthMax(root->left);
        int rightNode = depthMax(root->right);
        int maxNode = max(leftNode,rightNode) + 1;
        return maxNode;
    }
    int maxDepth(TreeNode* root) {
        return depthMax(root);
    }
};