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
        int ans=0;
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,1});
        while(!q.empty()){
            unsigned long long mini=ULLONG_MAX;
            unsigned long long maxi=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                auto[curr,len]=q.front();
                q.pop();
                //cout << len <<" ";
                maxi=max(maxi,len);
                mini=min(mini,len);
                if(curr->left){
                    q.push({curr->left,2*len});
                }
                if(curr->right){
                    q.push({curr->right,2*len+1});
                }
            }
            //cout << endl;
            int idx=(int)maxi-mini+1;
            ans=max(ans,idx);
        }
        return ans;
    }
};