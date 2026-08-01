class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> um;
        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0, 0}});   // {node, {col, row}}

        while (!q.empty()) {

            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int col = front.second.first;
            int row = front.second.second;

            um[col][row].insert(node->val);

            if (node->left)
                q.push({node->left, {col - 1, row + 1}});

            if (node->right)
                q.push({node->right, {col + 1, row + 1}});
        }

        vector<vector<int>> ans;

        for (auto &colMap : um) {

            vector<int> temp;

            for (auto &rowMap : colMap.second) {

                temp.insert(temp.end(),
                            rowMap.second.begin(),
                            rowMap.second.end());
            }

            ans.push_back(temp);
        }

        return ans;
    }
};