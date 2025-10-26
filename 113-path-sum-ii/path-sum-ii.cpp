class Solution {
public:
    void pathSumHelper(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int>& path) {
        if (root == nullptr) return;

        path.push_back(root->val);
        targetSum -= root->val;

        // If we reach a leaf and targetSum becomes 0 → valid path
        if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
            ans.push_back(path);
        } else {
            // Continue search in both subtrees
            pathSumHelper(root->left, targetSum, ans, path);
            pathSumHelper(root->right, targetSum, ans, path);
        }

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        pathSumHelper(root, targetSum, ans, path);
        return ans;
    }
};
