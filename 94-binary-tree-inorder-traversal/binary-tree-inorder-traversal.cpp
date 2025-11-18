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
    vector<int> answer;
    void traversalInOrder(TreeNode* root){
        if(!root) return ;

        traversalInOrder(root->left);
        answer.push_back(root->val);
        traversalInOrder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        traversalInOrder(root);
        return answer;
    }
};