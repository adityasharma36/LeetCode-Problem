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
    int rightNodeCount(TreeNode* root){
        int cnt = 0;
        while(root){
            cnt++;
            root= root->right;
        }
        return cnt;
    }
    int leftNodeCount(TreeNode* root){
        int cnt = 0;
        while(root){
            cnt++;
            root = root->left;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        int leftSide = leftNodeCount(root);
        int rightSide = rightNodeCount(root);
        if(leftSide == rightSide){
            return (1 << leftSide)-1;
        }

        int ls = countNodes(root->left);
        int rs = countNodes(root->right);

        return rs+ls+1;
    }
};