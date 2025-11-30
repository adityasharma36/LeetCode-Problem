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
    int widthOfBinaryTree(TreeNode* root) {

        queue<pair<TreeNode*,unsigned long long>> q;

        int maxWid = 0;

        q.push({root,0});

        while(!q.empty()){
            
            int totalSize = q.size();
            unsigned long long firstIndex = q.front().second;
            unsigned long long lastIndex = q.back().second;

            maxWid = max(maxWid , (int)(lastIndex-firstIndex + 1));


            for(int i = 0;i<totalSize;i++){
                auto curr = q.front();

                q.pop();
                if(curr.first->left){
                    q.push({curr.first->left,2*curr.second + 1});
                }
                if(curr.first->right){
                    q.push({curr.first->right,2*curr.second+2});
                }
            }
        }
        return maxWid;
    }
};