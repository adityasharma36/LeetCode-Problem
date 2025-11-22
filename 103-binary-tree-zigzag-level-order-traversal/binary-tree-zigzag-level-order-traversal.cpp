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
    vector<vector<int>> orderLevel(TreeNode* root){

        vector<vector<int>> ans;

        if(!root ) return ans;

        queue<TreeNode* > que;

        que.push(root);

        bool lToR = true;

        while(!que.empty()){

            int len = que.size();

            vector<int> temp(len);

            for(int i = 0;i<len;i++){

                TreeNode * front = que.front();

                que.pop();

                int index = (lToR) ? i : len - i-1;

                temp[index] = front->val;

                if(front->left){
                    que.push(front->left);
                }
                if(front->right){
                    que.push(front->right);
                }

            }
            lToR = !lToR;
            ans.push_back(temp);
        }
        return ans;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return orderLevel(root);
    }
};