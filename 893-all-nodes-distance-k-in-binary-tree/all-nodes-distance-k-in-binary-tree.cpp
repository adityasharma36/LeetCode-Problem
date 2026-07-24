/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mappingRoot(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&um){
        if(root->left){
            um[root->left]= root;
            mappingRoot(root->left,um);
        }
        if(root->right){
            um[root->right] = root;
            mappingRoot(root->right,um); 
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*>um;
        um[root]= nullptr;
        mappingRoot(root,um);
        unordered_map<TreeNode* , bool>isVisited;
        isVisited[target]= true;
        queue<TreeNode*>q;
        q.push(target);
        int currentLevel = 0;
       while (!q.empty()) {
    if (currentLevel == k)
        break;

    int size = q.size();

    for (int i = 0; i < size; i++) {
        TreeNode* front = q.front();
        q.pop();

        if (front->left && !isVisited[front->left]) {
            q.push(front->left);
            isVisited[front->left] = true;
        }

        if (front->right && !isVisited[front->right]) {
            q.push(front->right);
            isVisited[front->right] = true;
        }

        if (um[front] && !isVisited[um[front]]) {
            q.push(um[front]);
            isVisited[um[front]] = true;
        }
    }

    currentLevel++;
}
        vector<int> ans;
        while(!q.empty()){
           ans.push_back(q.front()->val);
           q.pop();
        }
        return ans;
    }
};