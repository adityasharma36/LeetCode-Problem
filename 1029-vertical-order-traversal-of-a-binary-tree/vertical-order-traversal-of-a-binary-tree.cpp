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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        

        vector<vector<int>>ans;

        if(!root) return ans;

        queue<pair<TreeNode* , pair<int,int>>>qu;

        qu.push({root, {0,0}});

        map<int,map<int,multiset<int>>>mp;

        while(!qu.empty()){

            auto front = qu.front();qu.pop();

            TreeNode* & node = front.first;

            auto coodinate = front.second;

            int &row  = coodinate.first;
            int &col = coodinate.second;

            mp[col][row].insert(node->val);

            if(node->left)
                qu.push({node->left,{row+1, col-1}});
            
            if(node->right)
                qu.push({node->right,{row+1, col+1}});

            
        }
        // store final vertical order into ans;
        for(auto it : mp){
            auto & colmap = it.second;
            vector<int > vline;
            for(auto colMap: colmap){
                auto & mSet = colMap.second;
                vline.insert(vline.end(),mSet.begin(),mSet.end());
            }
            ans.push_back(vline);
        }
        return ans;
    }
};