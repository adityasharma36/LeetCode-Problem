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
        if(!root) return 0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,1});
         long long  maxLen = INT_MIN;
        cout<<"max : "<<maxLen<<endl;
        while(!q.empty()){
            unsigned long long  size = q.size();
            cout<<size<<endl;
            unsigned long long firstIndex = q.front().second;
            unsigned long long lastIndex = q.back().second;
             long long len = lastIndex-firstIndex+1;
            cout<<"len: "<<len<<endl;
            maxLen = max(maxLen,len);
            cout<<"maxLen : "<<maxLen<<endl;
            for(unsigned long long i = 0;i<size;i++){
                 auto ele = q.front();
                 q.pop();
                 auto index = ele.second;
                 auto node = ele.first;

                 if(node->left){
                    q.push({node->left,2*index});
                 }
                 if(node->right){
                    q.push({node->right,2*index+1});
                 }
            }
        }
        return maxLen;
    }
};